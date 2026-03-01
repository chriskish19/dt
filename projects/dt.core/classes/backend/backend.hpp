/**********************************************************/
//
// File:
//
// Purpose:
//
// Project:
//
/**********************************************************/

#pragma once

#include CORE_NAMES_INCLUDE
#include CORE_STL_INCLUDE_PATH
#include CORE_PROCESSOR_INCLUDE_PATH
#include CORE_CODES_INCLUDE_PATH
#include CORE_DRAWING_INCLUDE_PATH
#include CORE_LOGGER_INCLUDE_PATH


namespace core {
	namespace backend {
		class Cbackend : public process {
		public:
			Cbackend(const std::vector<arg_entry>& v);
			core::codes begin();
		protected:
		};
	}
}