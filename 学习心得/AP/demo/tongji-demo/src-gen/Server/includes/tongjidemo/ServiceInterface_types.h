
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Server\includes\tongjidemo/ServiceInterface_types.h
 *        \brief  Input and output structures for methods, fields and application errors of service 'ServiceInterface'
 *
 *      \details  Definition of common input-/output structs used for simplified argument / marshalling handling. For all elements like methods, events fields structs with the related in-/output arguments are generated.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GENERATOR INFORMATION
 *  -------------------------------------------------------------------------------------------------------------------
 *    Generator Name: amsr_com_api
 *         Commit ID: 6cc205edba694b4589f76a5356343f3aa8f48375
 *********************************************************************************************************************/

#ifndef SERVER_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_TYPES_H_
#define SERVER_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_TYPES_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "tongjidemo/serviceinterface_common.h"

namespace tongjidemo {

namespace internal {

namespace methods {

/*!
 * \brief A class for service method 'add' used for type definitions.
 */
class add final {
 public:
  /*!
   * \brief Struct representing all output arguments of the service method.
   */
  struct Output {
    /*!
     * \brief Reference of output argument 'result' (/AUTOSAR/StdTypes/uint32_t)
     */
    std::uint32_t result;
  };

  /*!
   * \brief Struct representing all input arguments of the service method.
   */
  struct Input {
    /*!
     * \brief Reference of input argument 'num1' (/AUTOSAR/StdTypes/uint32_t)
     */
    std::uint32_t num1;
    /*!
     * \brief Reference of input argument 'num2' (/AUTOSAR/StdTypes/uint32_t)
     */
    std::uint32_t num2;
  };
};

}  // namespace methods

namespace fields {

/*!
 * \brief Data class for service field 'addResult'.
 * \remark generated
 */
class addResult final {
 public:
  /*!
   * \brief Return/output parameters of service field 'addResult'
   */
  using Output = std::uint32_t;
};


  /*!
 * \brief A class for field method 'addResult'Get used for type definitions.
 */
class addResultGet final {
 public:
  /*!
   * \brief Struct representing the field input data.
   */
  struct Input {};

  /*!
   * \brief Struct representing the field output value.
   */
  struct Output {
    /*!
     * \brief Reference of field value (/AUTOSAR/StdTypes/uint32_t)
     */
    std::uint32_t out_val;
  };
};

/*!
 * \brief A class for field method 'addResult'Set used for type definitions.
 */
class addResultSet final {
 public:
  /*!
   * \brief Struct representing the field input data.
   */
  struct Input {
    /*!
     * \brief Reference of field value (/AUTOSAR/StdTypes/uint32_t)
     */
    std::uint32_t in_val;

  };

  /*!
   * \brief Struct representing the field output value.
   */
  struct Output {
    /*!
     * \brief Reference of field value (/AUTOSAR/StdTypes/uint32_t)
     */
    std::uint32_t out_val;
  };
};

}  // namespace fields
}  // namespace internal

}  //  namespace tongjidemo

#endif  // SERVER_INCLUDES_TONGJIDEMO_SERVICEINTERFACE_TYPES_H_

