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
#ifndef SRC_COMMON_COMMANDLINEPARSER_COMMAND_LINE_PARSER_H_
#define SRC_COMMON_COMMANDLINEPARSER_COMMAND_LINE_PARSER_H_

namespace calc {
namespace commandlineparser {

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

class CommandLineParser;

/*! Option value when iterator is invalid. */
constexpr int kInvalidOption = -1;

/*! Argument index to mark an invalid Iterator. */
constexpr int kInvalidIteratorIndex = -1;

/*!
 * PSE54 and therefore not available on all supported OSs. This implementation supports:
 * Simple arguments, e.g.:
 *
 *     gcc main.c
 *
 * Short form options, e.g.:
 *
 *     gcc -v
 *
 * Short form options may require arguments, e.g.:
 *
 *     gcc -o myprog main.c
 *
 * Multiple short form options can be concatenated in one parameter, e.g.:
 *
 *     tar -xf archive.tar
 *
 * Usage:
 *
 *     CommandLineParser parser(argc, argv, OPTIONS)
 *
 * where OPTIONS is a string specifying allowed command line options where each option represented by a single letter
 * i.e. "-a", with optional ':' appended to indicate that the option has an argument. An invalid OPTIONS string leads
 * to an empty list of options. GetOption() will return kInvalidOption in this case. In debug build an invalid OPTIONS
 * string leads to an assertion.
 *
 * Example:
 *
 *     CommandLineParser parser(argc, argv, "ab:c");
 *     for(auto it: parser) {
 *       switch(it.GetOption()) {
 *         case 'a': FlagA = true; break;
 *         case 'b': ValueB = it.GetOptionArgument(); break;
 *         case 'c': FlagC = true; break;
 *         case '?': PrintUsage(); exit(); break;
 *       }
 *     }
 *
 */
class CommandLineParser final {
 public:
  /*!
   * Iterator implementation.
   */
  class Iterator final {
   public:
    /*!
     * \brief      Constructor
     *
     * \details    Creates the iterator and starts parsing the argument list.
     *
     * \param[in]  parent       The reference to the parent.
     * \param[in]  start_index  The starting argv index.
     */
    Iterator(const CommandLineParser& parent, int start_index);

    /*!
     * \brief Copy constructor
     */
    Iterator(const Iterator&) = default;

    /*!
     * \brief Copy assignment operator
     */
    Iterator& operator=(const Iterator&) = default;

    /*!
     * \brief      Equality operator.
     *
     * \param[in]  rhs   The right hand side
     *
     * \return     true if the objects are equal, false otherwise.
     */
    bool operator==(const Iterator& rhs) const noexcept {
      return &parent_ == &rhs.parent_ && arg_index_ == rhs.arg_index_;
    }

    /*!
     * \brief      Inequality operator.
     *
     * \param[in]  rhs   The right hand side
     *
     * \return     true if the objects are not equal, false otherwise.
     */
    bool operator!=(const Iterator& rhs) const noexcept { return !(*this == rhs); }

    /*!
     * \brief      Pre-increment operator.
     *
     * \return     Itself.
     */
    Iterator& operator++() {
      ParseNextOption();
      return *this;
    }

    /*!
     * \brief      Post-increment operator.
     *
     * \return     Copy of the iterator before increment.
     */
    Iterator operator++(int) {
      Iterator retval = *this;
      ++(*this);
      return retval;
    }

    /*!
     * \brief      Dereference operator.
     *
     * \return     Itself.
     */
    Iterator& operator*() { return *this; }

    /*!
     * \brief      Returns the symbol for the current option.
     *
     * \return     The symbol for the current option.
     * \retval     '?'              for unknown option.
     * \retval     kInvalidOption   for invalid iterator.
     */
    int GetOption() const noexcept;

    /*!
     * \brief      Returns the argument of the current option.
     *
     * \return     The option argument
     * \retval     nullptr    if the current option has no arguments.
     */
    const char* GetOptionArgument() const noexcept;

   private:
    /*!
     * \brief      The main update method of the library.
     *
     * \details    Performs the check of the next possible option and updates the iterator object.
     */
    void ParseNextOption() noexcept;

    /*!
     * \brief      Advances the processing of the current argument to the next character.
     */
    void GoToNextChar() noexcept;

    /*!
     * \brief      Sets option processing to the next argument.
     */
    void GoToNextArgument() noexcept;

    /*!
     * \brief      Stops parsing and sets current option to kInvalidOption.
     */
    void StopParsing() noexcept;

    /*!
     * Back reference to the parent object.
     */
    const CommandLineParser& parent_;

    /*!
     * Index of the argv which either contains the option currently referenced by the iterator or its argument.
     * The value is set to argc for an invalid iterator.
     */
    int arg_index_;

    /*!
     * Current position in the argv[arg_index] string referenced by the iterator.
     */
    int str_pos_;

    /*!
     * Symbol for the current option, '?' for unknown option or kInvalidOption for invalid iterator.
     */
    int cur_opt_;

    /*!
     * C-string of the possible argument for the current option. nullptr if there is none.
     */
    const char* cur_argument_;
  };  // End of class Iterator.

  /*!
   * \brief      Constructs the command line parser.
   *
   * \details    Creates the command line parser and validates the given command line arguments.
   *
   * \param[in]  argc             Number of command line arguments.
   * \param[in]  argv             Array containing the actual command line arguments.
   * \param[in]  allowed_options  String which specifies which options are allowed and which options require an
   *                              argument.
   */
  CommandLineParser(int argc, const char* const* argv, const char* allowed_options)
      : argc_{argc}, argv_{argv}, options_list_{allowed_options}, is_valid_{false} {
    ValidateOptionList();
  }

  /*!
   * Copy constructor
   */
  CommandLineParser(const CommandLineParser&) = default;

  /*!
   * \brief      Copy assignment operator
   *
   * \return     Itself.
   */
  CommandLineParser& operator=(const CommandLineParser&) = default;

  /*!
   * \brief      Part of the C++ iterator interface.
   *
   * \details    Returns iterator initialized to the first actual option after name of executable. argv[0] is the name
   *             representing executable and therefore is skipped.
   *
   * \return     Iterator to the begin of the option list.
   */
  Iterator begin() const noexcept { return Iterator{*this, 1}; }

  /*!
   * \brief      Part of the C++ iterator interface. Returns iterator to the end of the option list.
   *
   * \return     Iterator to the end of the option list.
   */
  Iterator end() const noexcept { return Iterator{*this, kInvalidIteratorIndex}; }

 private:
  /*!
   * \brief      Checks the passed option list string.
   *
   * \details    An error marks the parser as invalid. In release build this leads to an empty list of options. In
   *             debug build this leads to an assertion.
   */
  void ValidateOptionList() noexcept;

  /*!
   * Number of command line arguments.
   */
  const int argc_;

  /*!
   * Array containing the actual command line arguments.
   */
  const char* const* argv_;

  /*!
   * The allowed option string.
   */
  const char* options_list_;

  /*!
   * Stores whether the option list string was valid.
   */
  bool is_valid_;
};

}  // namespace commandlineparser
}  // namespace calc

#endif  // SRC_COMMON_COMMANDLINEPARSER_COMMAND_LINE_PARSER_H_
