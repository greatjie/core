﻿/*
 * (c) Copyright Ascensio System SIA 2010-2017
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */
#pragma once
#include "oox_package.h"
#include <cpdoccore/CPScopedPtr.h>
#include <cpdoccore/CPOptional.h>

namespace cpdoccore {
namespace oox {

class xlsx_pivot_cache_context;
typedef _CP_PTR(xlsx_pivot_cache_context) xlsx_pivot_cache_context_ptr;

class xlsx_pivots_context
{
public:
    xlsx_pivots_context();
    ~xlsx_pivots_context();

	void start_table();
	int end_table();

	void start_field();
		void set_field_name(std::wstring name);
		void set_field_type(int type);
		void set_field_function(int type);
		void set_field_user_function(std::wstring f);
		void add_field_subtotal(int function_type);
		void add_field_cache(int index, std::wstring value);
	void end_field();

	int get_count();

	void set_view_name(std::wstring name);
	void set_view_target_range(std::wstring ref);

	void set_source_range(std::wstring ref);

	void write_cache_definitions_to	(int index, std::wostream & strm);
	void write_cache_records_to		(int index, std::wostream & strm);
	void write_connections_to		(std::wostream & strm);

	void write_table_view_to		(int index, std::wostream & strm);

	void dump_rels_cache(int index, rels & Rels);
	void dump_rels_view	(int index, rels & Rels);

	void add_connections(std::wstring connections);
	bool is_connections();

private:
    class Impl;
    _CP_PTR(Impl) impl_;
              
};

}
}