/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file
 *        \brief  OS independent implementation of a command line parser.
 *
 *      \details  -
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "commandlineparser/command_line_parser.h"

#include <cassert>
#include <cstring>

namespace calc {
namespace commandlineparser {

/*! Index for the first character in a C-string. */
constexpr int kFirstCharacterIndex = 0;

/*! Index for the second character in a C-string. */
constexpr int kSecondCharacterIndex = 1;

CommandLineParser::Iterator::Iterator(const CommandLineParser& parent, int start_index)
    : parent_{parent},
      arg_index_{start_index},
      str_pos_{kFirstCharacterIndex},
      cur_opt_{kInvalidOption},
      cur_argument_{nullptr} {
  ParseNextOption();
}

void CommandLineParser::Iterator::GoToNextChar() noexcept {
  this->str_pos_++;
  /* #00 If next char is terminating zero, go to the next argument. */
  if (this->parent_.argv_[this->arg_index_][this->str_pos_] == '\0') {
    GoToNextArgument();
  }
}

void CommandLineParser::Iterator::GoToNextArgument() noexcept {
  this->arg_index_++;
  this->str_pos_ = kFirstCharacterIndex;
}

void CommandLineParser::Iterator::StopParsing() noexcept {
  this->arg_index_ = kInvalidIteratorIndex;
  this->cur_opt_ = kInvalidOption;
}

void CommandLineParser::Iterator::ParseNextOption() noexcept {
  cur_argument_ = nullptr;

  /* #00 Stop parsing... */
  if (arg_index_ == kInvalidIteratorIndex) {
    /* #00 ...If iterator is invalid */
    StopParsing();
  } else if (!parent_.is_valid_) {
    /* #00 ...If command line parser is invalid */
    StopParsing();
  } else if (arg_index_ >= parent_.argc_) {
    /* #00 ...If iterator is at the end of the argument list. */
    StopParsing();
  } else if (parent_.argv_[arg_index_] == nullptr) {
    /* #00 ...If current argument is a nullptr. */
    StopParsing();
  } else if (str_pos_ == kFirstCharacterIndex && parent_.argv_[arg_index_][kFirstCharacterIndex] != '-') {
    /* #00 ...If first character is not a minus character. */
    StopParsing();
  } else {
    /* #00 Skip first character (the minus character). */
    if (str_pos_ == kFirstCharacterIndex) {
      str_pos_++;
    }

    cur_opt_ = parent_.argv_[arg_index_][str_pos_];

    /* #00 Check whether the current character is part of the option list. */
    const char* opt = std::strchr(parent_.options_list_, cur_opt_);

    if (opt == nullptr) {
      /* #00 If current character is not part of the option list, return '?' and go to next character. */
      cur_opt_ = '?';
      GoToNextChar();
    } else if (*opt == '\0') {
      /* #00 If current character is '\0', return '?' and go to next argument. */
      /* This happens if the passed string contains only the minus character "-". */
      cur_opt_ = '?';
      GoToNextArgument();
    } else {
      /* #00 If option requires an argument. */
      /* Check for possible parameter ("a:" in the option list means -a has a parameter). */
      /* No out of bounds is possible: at least the \0 character will follow. */
      if (opt[kSecondCharacterIndex] == ':') {
        /* #00 Update current argument pointer. */
        cur_argument_ = &parent_.argv_[arg_index_][str_pos_ + 1];
        /* #00 If current parameter string ends with '\0' the argument is passed as a separate argument (e.g. "-a
         *     Value"). */
        if (*cur_argument_ == '\0') {
          /* #00 Increase current argument index. */
          arg_index_++;
          /* #00 If argument list ends with option which needs argument set option to '?' and set argument to nullptr.
           */
          if (arg_index_ >= parent_.argc_) {
            cur_argument_ = nullptr;
            cur_opt_ = '?';
          } else {
            /* #00 Update current argument pointer to next argument. */
            cur_argument_ = parent_.argv_[arg_index_];
            /* #00 Go to next argument. */
            GoToNextArgument();
          }
        } else {
          /* #00 If current option does not end with '\0' the argument is passed without space (e.g. "-aValue"). */
          GoToNextArgument();
        }
      } else {
        /* #00 Otherwise: Go to next character. */
        GoToNextChar();
      }
    }
  }
}

int CommandLineParser::Iterator::GetOption() const noexcept { return cur_opt_; }

const char* CommandLineParser::Iterator::GetOptionArgument() const noexcept { return cur_argument_; }

void CommandLineParser::ValidateOptionList() noexcept {
  if (options_list_ == nullptr) {
    is_valid_ = false;
    assert(false && "Option list must not be nullptr.");
  } else if (*options_list_ == '\0') {
    is_valid_ = false;
    assert(false && "Option list must not be empty string.");
  } else {
    auto isAlphaChar = [](char c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); };
    auto prev = [this](const char* ptr) { return (ptr != this->options_list_ ? *(ptr - 1) : '\0'); };

    const char* ptr = options_list_;
    for (; *ptr != '\0'; ptr++) {
      if (*ptr == ':') {
        if (!isAlphaChar(prev(ptr))) {
          assert(false && "Argument specifier ':' must follow an alphabetic character.");
          break;
        }
      } else if (!isAlphaChar(*ptr)) {
        assert(false && "Option list must only contain alphabetic characters or ':' to specify an argument.");
        break;
      }
    }
    /* When the option string was not processed completely an error has occurred. */
    is_valid_ = (*ptr == '\0');
  }
}

}  // namespace commandlineparser
}  // namespace calc
