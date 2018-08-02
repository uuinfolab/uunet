/**
 * This module enables attribute management.
 *
 * The supported data types are defined in AttributeType.h.
 * Library-specific types are defined in Text.h and Time.h.
 *
 * Attribute.h, Value.h and conversion.h provide, respectively:
 * - attribute metadata (name and data type)
 * - attribute values, of the different supported data types
 * - conversions among types.
 *
 * `AttributeStore`s are containers allowing the creation of attributes and
 * associating attribute values to object identifiers. Currently,
 * a main memory implementation of an `AttributeStore` is available.
 *
 * History:
 * - 2018.01.01 file adapted from version 1.0 of the multinet library
 */

#ifndef UU_CORE_ATTRIBUTES_H_
#define UU_CORE_ATTRIBUTES_H_

#include "core/attributes/Attribute.h"
#include "core/attributes/AttributeStore.h"
#include "core/attributes/AttributeType.h"
#include "core/attributes/conversion.h"
#include "core/attributes/MainMemoryAttributeStore.h"
#include "core/attributes/Text.h"
#include "core/attributes/Time.h"
#include "core/attributes/Value.h"

#endif
