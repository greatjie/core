#pragma once

#include <iosfwd>
#include <vector>
#include <cpdoccore/CPOptional.h>
#include <cpdoccore/xml/nodetype.h>
#include <cpdoccore/xml/simple_xml_writer.h>

#include "office_elements_create.h"


#include "bool.h"
#include "length.h"
#include "style_ref.h"

namespace cpdoccore { 
namespace odf {


class office_annotation_attr
{
public:
   	void serialize(CP_ATTR_NODE);   

public:
	_CP_OPT(length) svg_y_;
	_CP_OPT(length) svg_x_;
 	_CP_OPT(length) svg_width_;
	_CP_OPT(length) svg_height_;

	_CP_OPT(length) caption_point_y_;
	_CP_OPT(length) caption_point_x_;

	_CP_OPT(Bool) display_;

	 _CP_OPT(style_ref) draw_text_style_name_;
	 _CP_OPT(style_ref) draw_style_name_;
};

/// \brief  dc:date
class dc_date : public office_element_impl<dc_date>
{
public:
    static const wchar_t * ns;
    static const wchar_t * name;
    static const xml::NodeType xml_type = xml::typeElement;
    static const ElementType type = typeDcDate;
    CPDOCCORE_DEFINE_VISITABLE();
	
	virtual void create_child_element( const ::std::wstring & Ns, const ::std::wstring & Name){}
	virtual void add_child_element( office_element_ptr & child_element){}

	virtual void serialize(std::wostream & _Wostream);

    virtual void add_text(const std::wstring & Text);

	std::wstring content_;

};
CP_REGISTER_OFFICE_ELEMENT2(dc_date);

/// \brief  dc:creator
class dc_creator : public office_element_impl<dc_creator>
{
public:
    static const wchar_t * ns;
    static const wchar_t * name;
    static const xml::NodeType xml_type = xml::typeElement;
    static const ElementType type = typeDcCreator;
    CPDOCCORE_DEFINE_VISITABLE();

	virtual void create_child_element( const ::std::wstring & Ns, const ::std::wstring & Name){}
	virtual void add_child_element( office_element_ptr & child_element){}

	virtual void serialize(std::wostream & _Wostream);

    virtual void add_text(const std::wstring & Text);

	std::wstring content_;

};
CP_REGISTER_OFFICE_ELEMENT2(dc_creator);

/// \brief  office:annotation 
class office_annotation : public office_element_impl<office_annotation>
{
public:
    static const wchar_t * ns;
    static const wchar_t * name;
    static const xml::NodeType xml_type = xml::typeElement;
    static const ElementType type = typeOfficeAnnotation;
    CPDOCCORE_DEFINE_VISITABLE();

	virtual void create_child_element( const ::std::wstring & Ns, const ::std::wstring & Name);
	virtual void add_child_element( office_element_ptr & child_element);

	virtual void serialize(std::wostream & _Wostream);
	
	office_annotation_attr office_annotation_attr_;

private:
    office_element_ptr_array content_;

    office_element_ptr dc_date_;
    office_element_ptr dc_creator_;


};
CP_REGISTER_OFFICE_ELEMENT2(office_annotation);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//officeooo:annotation
class officeooo_annotation : public office_element_impl<officeooo_annotation>
{
public:
    static const wchar_t * ns;
    static const wchar_t * name;
    static const xml::NodeType xml_type = xml::typeElement;
    static const ElementType type = typeOfficeAnnotation;
    CPDOCCORE_DEFINE_VISITABLE();

	virtual void create_child_element( const ::std::wstring & Ns, const ::std::wstring & Name);
	virtual void add_child_element( office_element_ptr & child_element);

	virtual void serialize(std::wostream & _Wostream);


private:
    office_element_ptr_array content_;
	office_annotation_attr office_annotation_attr_;

    office_element_ptr dc_date_;
    office_element_ptr dc_creator_;


};
CP_REGISTER_OFFICE_ELEMENT2(officeooo_annotation);
}
}
