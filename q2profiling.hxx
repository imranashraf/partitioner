// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

#ifndef Q2PROFILING_HXX
#define Q2PROFILING_HXX

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 3030000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_TREE_USE_CHAR
#define XSD_CXX_TREE_USE_CHAR
#endif

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/types.hxx>

#include <xsd/cxx/xml/error-handler.hxx>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

#include <xsd/cxx/tree/parsing.hxx>
#include <xsd/cxx/tree/parsing/byte.hxx>
#include <xsd/cxx/tree/parsing/unsigned-byte.hxx>
#include <xsd/cxx/tree/parsing/short.hxx>
#include <xsd/cxx/tree/parsing/unsigned-short.hxx>
#include <xsd/cxx/tree/parsing/int.hxx>
#include <xsd/cxx/tree/parsing/unsigned-int.hxx>
#include <xsd/cxx/tree/parsing/long.hxx>
#include <xsd/cxx/tree/parsing/unsigned-long.hxx>
#include <xsd/cxx/tree/parsing/boolean.hxx>
#include <xsd/cxx/tree/parsing/float.hxx>
#include <xsd/cxx/tree/parsing/double.hxx>
#include <xsd/cxx/tree/parsing/decimal.hxx>

namespace xml_schema
{
  // anyType and anySimpleType.
  //
  typedef ::xsd::cxx::tree::type type;
  typedef ::xsd::cxx::tree::simple_type< type > simple_type;
  typedef ::xsd::cxx::tree::type container;

  // 8-bit
  //
  typedef signed char byte;
  typedef unsigned char unsigned_byte;

  // 16-bit
  //
  typedef short short_;
  typedef unsigned short unsigned_short;

  // 32-bit
  //
  typedef int int_;
  typedef unsigned int unsigned_int;

  // 64-bit
  //
  typedef long long long_;
  typedef unsigned long long unsigned_long;

  // Supposed to be arbitrary-length integral types.
  //
  typedef long long integer;
  typedef long long non_positive_integer;
  typedef unsigned long long non_negative_integer;
  typedef unsigned long long positive_integer;
  typedef long long negative_integer;

  // Boolean.
  //
  typedef bool boolean;

  // Floating-point types.
  //
  typedef float float_;
  typedef double double_;
  typedef double decimal;

  // String types.
  //
  typedef ::xsd::cxx::tree::string< char, simple_type > string;
  typedef ::xsd::cxx::tree::normalized_string< char, string > normalized_string;
  typedef ::xsd::cxx::tree::token< char, normalized_string > token;
  typedef ::xsd::cxx::tree::name< char, token > name;
  typedef ::xsd::cxx::tree::nmtoken< char, token > nmtoken;
  typedef ::xsd::cxx::tree::nmtokens< char, simple_type, nmtoken > nmtokens;
  typedef ::xsd::cxx::tree::ncname< char, name > ncname;
  typedef ::xsd::cxx::tree::language< char, token > language;

  // ID/IDREF.
  //
  typedef ::xsd::cxx::tree::id< char, ncname > id;
  typedef ::xsd::cxx::tree::idref< char, ncname, type > idref;
  typedef ::xsd::cxx::tree::idrefs< char, simple_type, idref > idrefs;

  // URI.
  //
  typedef ::xsd::cxx::tree::uri< char, simple_type > uri;

  // Qualified name.
  //
  typedef ::xsd::cxx::tree::qname< char, simple_type, uri, ncname > qname;

  // Binary.
  //
  typedef ::xsd::cxx::tree::buffer< char > buffer;
  typedef ::xsd::cxx::tree::base64_binary< char, simple_type > base64_binary;
  typedef ::xsd::cxx::tree::hex_binary< char, simple_type > hex_binary;

  // Date/time.
  //
  typedef ::xsd::cxx::tree::time_zone time_zone;
  typedef ::xsd::cxx::tree::date< char, simple_type > date;
  typedef ::xsd::cxx::tree::date_time< char, simple_type > date_time;
  typedef ::xsd::cxx::tree::duration< char, simple_type > duration;
  typedef ::xsd::cxx::tree::gday< char, simple_type > gday;
  typedef ::xsd::cxx::tree::gmonth< char, simple_type > gmonth;
  typedef ::xsd::cxx::tree::gmonth_day< char, simple_type > gmonth_day;
  typedef ::xsd::cxx::tree::gyear< char, simple_type > gyear;
  typedef ::xsd::cxx::tree::gyear_month< char, simple_type > gyear_month;
  typedef ::xsd::cxx::tree::time< char, simple_type > time;

  // Entity.
  //
  typedef ::xsd::cxx::tree::entity< char, ncname > entity;
  typedef ::xsd::cxx::tree::entities< char, simple_type, entity > entities;

  // Flags and properties.
  //
  typedef ::xsd::cxx::tree::flags flags;
  typedef ::xsd::cxx::tree::properties< char > properties;

  // Parsing/serialization diagnostics.
  //
  typedef ::xsd::cxx::tree::severity severity;
  typedef ::xsd::cxx::tree::error< char > error;
  typedef ::xsd::cxx::tree::diagnostics< char > diagnostics;

  // Exceptions.
  //
  typedef ::xsd::cxx::tree::exception< char > exception;
  typedef ::xsd::cxx::tree::bounds< char > bounds;
  typedef ::xsd::cxx::tree::duplicate_id< char > duplicate_id;
  typedef ::xsd::cxx::tree::parsing< char > parsing;
  typedef ::xsd::cxx::tree::expected_element< char > expected_element;
  typedef ::xsd::cxx::tree::unexpected_element< char > unexpected_element;
  typedef ::xsd::cxx::tree::expected_attribute< char > expected_attribute;
  typedef ::xsd::cxx::tree::unexpected_enumerator< char > unexpected_enumerator;
  typedef ::xsd::cxx::tree::expected_text_content< char > expected_text_content;
  typedef ::xsd::cxx::tree::no_prefix_mapping< char > no_prefix_mapping;

  // Error handler callback interface.
  //
  typedef ::xsd::cxx::xml::error_handler< char > error_handler;

  // DOM interaction.
  //
  namespace dom
  {
    // Automatic pointer for DOMDocument.
    //
    using ::xsd::cxx::xml::dom::auto_ptr;

#ifndef XSD_CXX_TREE_TREE_NODE_KEY__XML_SCHEMA
#define XSD_CXX_TREE_TREE_NODE_KEY__XML_SCHEMA
    // DOM user data key for back pointers to tree nodes.
    //
    const XMLCh* const tree_node_key = ::xsd::cxx::tree::user_data_keys::node;
#endif
  }
}

// Forward declarations.
//
namespace q2profiling
{
  class FunctionType;
  class MetricType;
  class MeasurementType;
  class ChannelType;
  class CallType;
  class TargetType;
  class ApplicationType;
  class ProfilesType;
  class metrics;
  class statistics;
  class functions;
  class QDUGraph;
  class CallGraph;
}


#include <memory>    // std::auto_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

namespace q2profiling
{
  class FunctionType: public ::xml_schema::type
  {
    public:
    // metrics
    // 
    typedef ::q2profiling::metrics metrics_type;
    typedef ::xsd::cxx::tree::traits< metrics_type, char > metrics_traits;

    const metrics_type&
    metrics () const;

    metrics_type&
    metrics ();

    void
    metrics (const metrics_type& x);

    void
    metrics (::std::auto_ptr< metrics_type > p);

    // statistics
    // 
    typedef ::q2profiling::statistics statistics_type;
    typedef ::xsd::cxx::tree::traits< statistics_type, char > statistics_traits;

    const statistics_type&
    statistics () const;

    statistics_type&
    statistics ();

    void
    statistics (const statistics_type& x);

    void
    statistics (::std::auto_ptr< statistics_type > p);

    // name
    // 
    typedef ::xml_schema::string name_type;
    typedef ::xsd::cxx::tree::traits< name_type, char > name_traits;

    const name_type&
    name () const;

    name_type&
    name ();

    void
    name (const name_type& x);

    void
    name (::std::auto_ptr< name_type > p);

    // Constructors.
    //
    FunctionType (const metrics_type&,
                  const statistics_type&,
                  const name_type&);

    FunctionType (::std::auto_ptr< metrics_type >&,
                  ::std::auto_ptr< statistics_type >&,
                  const name_type&);

    FunctionType (const ::xercesc::DOMElement& e,
                  ::xml_schema::flags f = 0,
                  ::xml_schema::container* c = 0);

    FunctionType (const FunctionType& x,
                  ::xml_schema::flags f = 0,
                  ::xml_schema::container* c = 0);

    virtual FunctionType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~FunctionType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< metrics_type > metrics_;
    ::xsd::cxx::tree::one< statistics_type > statistics_;
    ::xsd::cxx::tree::one< name_type > name_;
  };

  class MetricType: public ::xsd::cxx::tree::fundamental_base< ::xml_schema::double_, char, ::xml_schema::simple_type, ::xsd::cxx::tree::schema_type::double_ >
  {
    public:
    // name
    // 
    typedef ::xml_schema::string name_type;
    typedef ::xsd::cxx::tree::traits< name_type, char > name_traits;

    const name_type&
    name () const;

    name_type&
    name ();

    void
    name (const name_type& x);

    void
    name (::std::auto_ptr< name_type > p);

    // type
    // 
    typedef ::xml_schema::string type_type;
    typedef ::xsd::cxx::tree::traits< type_type, char > type_traits;

    const type_type&
    type () const;

    type_type&
    type ();

    void
    type (const type_type& x);

    void
    type (::std::auto_ptr< type_type > p);

    // Constructors.
    //
    MetricType (const ::xml_schema::double_&,
                const name_type&,
                const type_type&);

    MetricType (const ::xercesc::DOMElement& e,
                ::xml_schema::flags f = 0,
                ::xml_schema::container* c = 0);

    MetricType (const MetricType& x,
                ::xml_schema::flags f = 0,
                ::xml_schema::container* c = 0);

    virtual MetricType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~MetricType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< name_type > name_;
    ::xsd::cxx::tree::one< type_type > type_;
  };

  class MeasurementType: public ::xsd::cxx::tree::fundamental_base< ::xml_schema::double_, char, ::xml_schema::simple_type, ::xsd::cxx::tree::schema_type::double_ >
  {
    public:
    // unit
    // 
    typedef ::xml_schema::string unit_type;
    typedef ::xsd::cxx::tree::optional< unit_type > unit_optional;
    typedef ::xsd::cxx::tree::traits< unit_type, char > unit_traits;

    const unit_optional&
    unit () const;

    unit_optional&
    unit ();

    void
    unit (const unit_type& x);

    void
    unit (const unit_optional& x);

    void
    unit (::std::auto_ptr< unit_type > p);

    // name
    // 
    typedef ::xml_schema::string name_type;
    typedef ::xsd::cxx::tree::traits< name_type, char > name_traits;

    const name_type&
    name () const;

    name_type&
    name ();

    void
    name (const name_type& x);

    void
    name (::std::auto_ptr< name_type > p);

    // type
    // 
    typedef ::xml_schema::string type_type;
    typedef ::xsd::cxx::tree::traits< type_type, char > type_traits;

    const type_type&
    type () const;

    type_type&
    type ();

    void
    type (const type_type& x);

    void
    type (::std::auto_ptr< type_type > p);

    // by
    // 
    typedef ::xml_schema::string by_type;
    typedef ::xsd::cxx::tree::traits< by_type, char > by_traits;

    const by_type&
    by () const;

    by_type&
    by ();

    void
    by (const by_type& x);

    void
    by (::std::auto_ptr< by_type > p);

    // Constructors.
    //
    MeasurementType (const ::xml_schema::double_&,
                     const name_type&,
                     const type_type&,
                     const by_type&);

    MeasurementType (const ::xercesc::DOMElement& e,
                     ::xml_schema::flags f = 0,
                     ::xml_schema::container* c = 0);

    MeasurementType (const MeasurementType& x,
                     ::xml_schema::flags f = 0,
                     ::xml_schema::container* c = 0);

    virtual MeasurementType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~MeasurementType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    unit_optional unit_;
    ::xsd::cxx::tree::one< name_type > name_;
    ::xsd::cxx::tree::one< type_type > type_;
    ::xsd::cxx::tree::one< by_type > by_;
  };

  class ChannelType: public ::xml_schema::type
  {
    public:
    // UnMA
    // 
    typedef ::xml_schema::int_ UnMA_type;
    typedef ::xsd::cxx::tree::optional< UnMA_type > UnMA_optional;
    typedef ::xsd::cxx::tree::traits< UnMA_type, char > UnMA_traits;

    const UnMA_optional&
    UnMA () const;

    UnMA_optional&
    UnMA ();

    void
    UnMA (const UnMA_type& x);

    void
    UnMA (const UnMA_optional& x);

    // hUnMA
    // 
    typedef ::xml_schema::int_ hUnMA_type;
    typedef ::xsd::cxx::tree::optional< hUnMA_type > hUnMA_optional;
    typedef ::xsd::cxx::tree::traits< hUnMA_type, char > hUnMA_traits;

    const hUnMA_optional&
    hUnMA () const;

    hUnMA_optional&
    hUnMA ();

    void
    hUnMA (const hUnMA_type& x);

    void
    hUnMA (const hUnMA_optional& x);

    // bytes
    // 
    typedef ::xml_schema::int_ bytes_type;
    typedef ::xsd::cxx::tree::optional< bytes_type > bytes_optional;
    typedef ::xsd::cxx::tree::traits< bytes_type, char > bytes_traits;

    const bytes_optional&
    bytes () const;

    bytes_optional&
    bytes ();

    void
    bytes (const bytes_type& x);

    void
    bytes (const bytes_optional& x);

    // hBytes
    // 
    typedef ::xml_schema::int_ hBytes_type;
    typedef ::xsd::cxx::tree::optional< hBytes_type > hBytes_optional;
    typedef ::xsd::cxx::tree::traits< hBytes_type, char > hBytes_traits;

    const hBytes_optional&
    hBytes () const;

    hBytes_optional&
    hBytes ();

    void
    hBytes (const hBytes_type& x);

    void
    hBytes (const hBytes_optional& x);

    // Values
    // 
    typedef ::xml_schema::int_ Values_type;
    typedef ::xsd::cxx::tree::optional< Values_type > Values_optional;
    typedef ::xsd::cxx::tree::traits< Values_type, char > Values_traits;

    const Values_optional&
    Values () const;

    Values_optional&
    Values ();

    void
    Values (const Values_type& x);

    void
    Values (const Values_optional& x);

    // hValues
    // 
    typedef ::xml_schema::int_ hValues_type;
    typedef ::xsd::cxx::tree::optional< hValues_type > hValues_optional;
    typedef ::xsd::cxx::tree::traits< hValues_type, char > hValues_traits;

    const hValues_optional&
    hValues () const;

    hValues_optional&
    hValues ();

    void
    hValues (const hValues_type& x);

    void
    hValues (const hValues_optional& x);

    // producer
    // 
    typedef ::xml_schema::string producer_type;
    typedef ::xsd::cxx::tree::traits< producer_type, char > producer_traits;

    const producer_type&
    producer () const;

    producer_type&
    producer ();

    void
    producer (const producer_type& x);

    void
    producer (::std::auto_ptr< producer_type > p);

    // consumer
    // 
    typedef ::xml_schema::string consumer_type;
    typedef ::xsd::cxx::tree::traits< consumer_type, char > consumer_traits;

    const consumer_type&
    consumer () const;

    consumer_type&
    consumer ();

    void
    consumer (const consumer_type& x);

    void
    consumer (::std::auto_ptr< consumer_type > p);

    // Constructors.
    //
    ChannelType (const producer_type&,
                 const consumer_type&);

    ChannelType (const ::xercesc::DOMElement& e,
                 ::xml_schema::flags f = 0,
                 ::xml_schema::container* c = 0);

    ChannelType (const ChannelType& x,
                 ::xml_schema::flags f = 0,
                 ::xml_schema::container* c = 0);

    virtual ChannelType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~ChannelType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    UnMA_optional UnMA_;
    hUnMA_optional hUnMA_;
    bytes_optional bytes_;
    hBytes_optional hBytes_;
    Values_optional Values_;
    hValues_optional hValues_;
    ::xsd::cxx::tree::one< producer_type > producer_;
    ::xsd::cxx::tree::one< consumer_type > consumer_;
  };

  class CallType: public ::xml_schema::type
  {
    public:
    // calls
    // 
    typedef ::xml_schema::int_ calls_type;
    typedef ::xsd::cxx::tree::optional< calls_type > calls_optional;
    typedef ::xsd::cxx::tree::traits< calls_type, char > calls_traits;

    const calls_optional&
    calls () const;

    calls_optional&
    calls ();

    void
    calls (const calls_type& x);

    void
    calls (const calls_optional& x);

    // contribution
    // 
    typedef ::xml_schema::double_ contribution_type;
    typedef ::xsd::cxx::tree::optional< contribution_type > contribution_optional;
    typedef ::xsd::cxx::tree::traits< contribution_type, char, ::xsd::cxx::tree::schema_type::double_ > contribution_traits;

    const contribution_optional&
    contribution () const;

    contribution_optional&
    contribution ();

    void
    contribution (const contribution_type& x);

    void
    contribution (const contribution_optional& x);

    // caller
    // 
    typedef ::xml_schema::string caller_type;
    typedef ::xsd::cxx::tree::traits< caller_type, char > caller_traits;

    const caller_type&
    caller () const;

    caller_type&
    caller ();

    void
    caller (const caller_type& x);

    void
    caller (::std::auto_ptr< caller_type > p);

    // callee
    // 
    typedef ::xml_schema::string callee_type;
    typedef ::xsd::cxx::tree::traits< callee_type, char > callee_traits;

    const callee_type&
    callee () const;

    callee_type&
    callee ();

    void
    callee (const callee_type& x);

    void
    callee (::std::auto_ptr< callee_type > p);

    // Constructors.
    //
    CallType (const caller_type&,
              const callee_type&);

    CallType (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    CallType (const CallType& x,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    virtual CallType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~CallType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    calls_optional calls_;
    contribution_optional contribution_;
    ::xsd::cxx::tree::one< caller_type > caller_;
    ::xsd::cxx::tree::one< callee_type > callee_;
  };

  class TargetType: public ::xml_schema::type
  {
    public:
    // measurement
    // 
    typedef ::q2profiling::MeasurementType measurement_type;
    typedef ::xsd::cxx::tree::sequence< measurement_type > measurement_sequence;
    typedef measurement_sequence::iterator measurement_iterator;
    typedef measurement_sequence::const_iterator measurement_const_iterator;
    typedef ::xsd::cxx::tree::traits< measurement_type, char > measurement_traits;

    const measurement_sequence&
    measurement () const;

    measurement_sequence&
    measurement ();

    void
    measurement (const measurement_sequence& s);

    // name
    // 
    typedef ::xml_schema::string name_type;
    typedef ::xsd::cxx::tree::traits< name_type, char > name_traits;

    const name_type&
    name () const;

    name_type&
    name ();

    void
    name (const name_type& x);

    void
    name (::std::auto_ptr< name_type > p);

    // Constructors.
    //
    TargetType (const name_type&);

    TargetType (const ::xercesc::DOMElement& e,
                ::xml_schema::flags f = 0,
                ::xml_schema::container* c = 0);

    TargetType (const TargetType& x,
                ::xml_schema::flags f = 0,
                ::xml_schema::container* c = 0);

    virtual TargetType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~TargetType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    measurement_sequence measurement_;
    ::xsd::cxx::tree::one< name_type > name_;
  };

  class ApplicationType: public ::xml_schema::type
  {
    public:
    // location
    // 
    typedef ::xml_schema::string location_type;
    typedef ::xsd::cxx::tree::traits< location_type, char > location_traits;

    const location_type&
    location () const;

    location_type&
    location ();

    void
    location (const location_type& x);

    void
    location (::std::auto_ptr< location_type > p);

    // workdir
    // 
    typedef ::xml_schema::string workdir_type;
    typedef ::xsd::cxx::tree::traits< workdir_type, char > workdir_traits;

    const workdir_type&
    workdir () const;

    workdir_type&
    workdir ();

    void
    workdir (const workdir_type& x);

    void
    workdir (::std::auto_ptr< workdir_type > p);

    // arguments
    // 
    typedef ::xml_schema::string arguments_type;
    typedef ::xsd::cxx::tree::traits< arguments_type, char > arguments_traits;

    const arguments_type&
    arguments () const;

    arguments_type&
    arguments ();

    void
    arguments (const arguments_type& x);

    void
    arguments (::std::auto_ptr< arguments_type > p);

    // date
    // 
    typedef ::xml_schema::date_time date_type;
    typedef ::xsd::cxx::tree::traits< date_type, char > date_traits;

    const date_type&
    date () const;

    date_type&
    date ();

    void
    date (const date_type& x);

    void
    date (::std::auto_ptr< date_type > p);

    // functions
    // 
    typedef ::q2profiling::functions functions_type;
    typedef ::xsd::cxx::tree::traits< functions_type, char > functions_traits;

    const functions_type&
    functions () const;

    functions_type&
    functions ();

    void
    functions (const functions_type& x);

    void
    functions (::std::auto_ptr< functions_type > p);

    // QDUGraph
    // 
    typedef ::q2profiling::QDUGraph QDUGraph_type;
    typedef ::xsd::cxx::tree::traits< QDUGraph_type, char > QDUGraph_traits;

    const QDUGraph_type&
    QDUGraph () const;

    QDUGraph_type&
    QDUGraph ();

    void
    QDUGraph (const QDUGraph_type& x);

    void
    QDUGraph (::std::auto_ptr< QDUGraph_type > p);

    // CallGraph
    // 
    typedef ::q2profiling::CallGraph CallGraph_type;
    typedef ::xsd::cxx::tree::traits< CallGraph_type, char > CallGraph_traits;

    const CallGraph_type&
    CallGraph () const;

    CallGraph_type&
    CallGraph ();

    void
    CallGraph (const CallGraph_type& x);

    void
    CallGraph (::std::auto_ptr< CallGraph_type > p);

    // name
    // 
    typedef ::xml_schema::string name_type;
    typedef ::xsd::cxx::tree::traits< name_type, char > name_traits;

    const name_type&
    name () const;

    name_type&
    name ();

    void
    name (const name_type& x);

    void
    name (::std::auto_ptr< name_type > p);

    // category
    // 
    typedef ::xml_schema::string category_type;
    typedef ::xsd::cxx::tree::optional< category_type > category_optional;
    typedef ::xsd::cxx::tree::traits< category_type, char > category_traits;

    const category_optional&
    category () const;

    category_optional&
    category ();

    void
    category (const category_type& x);

    void
    category (const category_optional& x);

    void
    category (::std::auto_ptr< category_type > p);

    // Constructors.
    //
    ApplicationType (const location_type&,
                     const workdir_type&,
                     const arguments_type&,
                     const date_type&,
                     const functions_type&,
                     const QDUGraph_type&,
                     const CallGraph_type&,
                     const name_type&);

    ApplicationType (const location_type&,
                     const workdir_type&,
                     const arguments_type&,
                     const date_type&,
                     ::std::auto_ptr< functions_type >&,
                     ::std::auto_ptr< QDUGraph_type >&,
                     ::std::auto_ptr< CallGraph_type >&,
                     const name_type&);

    ApplicationType (const ::xercesc::DOMElement& e,
                     ::xml_schema::flags f = 0,
                     ::xml_schema::container* c = 0);

    ApplicationType (const ApplicationType& x,
                     ::xml_schema::flags f = 0,
                     ::xml_schema::container* c = 0);

    virtual ApplicationType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~ApplicationType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< location_type > location_;
    ::xsd::cxx::tree::one< workdir_type > workdir_;
    ::xsd::cxx::tree::one< arguments_type > arguments_;
    ::xsd::cxx::tree::one< date_type > date_;
    ::xsd::cxx::tree::one< functions_type > functions_;
    ::xsd::cxx::tree::one< QDUGraph_type > QDUGraph_;
    ::xsd::cxx::tree::one< CallGraph_type > CallGraph_;
    ::xsd::cxx::tree::one< name_type > name_;
    category_optional category_;
  };

  class ProfilesType: public ::xml_schema::type
  {
    public:
    // application
    // 
    typedef ::q2profiling::ApplicationType application_type;
    typedef ::xsd::cxx::tree::sequence< application_type > application_sequence;
    typedef application_sequence::iterator application_iterator;
    typedef application_sequence::const_iterator application_const_iterator;
    typedef ::xsd::cxx::tree::traits< application_type, char > application_traits;

    const application_sequence&
    application () const;

    application_sequence&
    application ();

    void
    application (const application_sequence& s);

    // Constructors.
    //
    ProfilesType ();

    ProfilesType (const ::xercesc::DOMElement& e,
                  ::xml_schema::flags f = 0,
                  ::xml_schema::container* c = 0);

    ProfilesType (const ProfilesType& x,
                  ::xml_schema::flags f = 0,
                  ::xml_schema::container* c = 0);

    virtual ProfilesType*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~ProfilesType ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    application_sequence application_;
  };

  class metrics: public ::xml_schema::type
  {
    public:
    // metric
    // 
    typedef ::q2profiling::MetricType metric_type;
    typedef ::xsd::cxx::tree::sequence< metric_type > metric_sequence;
    typedef metric_sequence::iterator metric_iterator;
    typedef metric_sequence::const_iterator metric_const_iterator;
    typedef ::xsd::cxx::tree::traits< metric_type, char > metric_traits;

    const metric_sequence&
    metric () const;

    metric_sequence&
    metric ();

    void
    metric (const metric_sequence& s);

    // Constructors.
    //
    metrics ();

    metrics (const ::xercesc::DOMElement& e,
             ::xml_schema::flags f = 0,
             ::xml_schema::container* c = 0);

    metrics (const metrics& x,
             ::xml_schema::flags f = 0,
             ::xml_schema::container* c = 0);

    virtual metrics*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~metrics ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    metric_sequence metric_;
  };

  class statistics: public ::xml_schema::type
  {
    public:
    // measurement
    // 
    typedef ::q2profiling::MeasurementType measurement_type;
    typedef ::xsd::cxx::tree::sequence< measurement_type > measurement_sequence;
    typedef measurement_sequence::iterator measurement_iterator;
    typedef measurement_sequence::const_iterator measurement_const_iterator;
    typedef ::xsd::cxx::tree::traits< measurement_type, char > measurement_traits;

    const measurement_sequence&
    measurement () const;

    measurement_sequence&
    measurement ();

    void
    measurement (const measurement_sequence& s);

    // target
    // 
    typedef ::q2profiling::TargetType target_type;
    typedef ::xsd::cxx::tree::sequence< target_type > target_sequence;
    typedef target_sequence::iterator target_iterator;
    typedef target_sequence::const_iterator target_const_iterator;
    typedef ::xsd::cxx::tree::traits< target_type, char > target_traits;

    const target_sequence&
    target () const;

    target_sequence&
    target ();

    void
    target (const target_sequence& s);

    // Constructors.
    //
    statistics ();

    statistics (const ::xercesc::DOMElement& e,
                ::xml_schema::flags f = 0,
                ::xml_schema::container* c = 0);

    statistics (const statistics& x,
                ::xml_schema::flags f = 0,
                ::xml_schema::container* c = 0);

    virtual statistics*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~statistics ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    measurement_sequence measurement_;
    target_sequence target_;
  };

  class functions: public ::xml_schema::type
  {
    public:
    // function
    // 
    typedef ::q2profiling::FunctionType function_type;
    typedef ::xsd::cxx::tree::sequence< function_type > function_sequence;
    typedef function_sequence::iterator function_iterator;
    typedef function_sequence::const_iterator function_const_iterator;
    typedef ::xsd::cxx::tree::traits< function_type, char > function_traits;

    const function_sequence&
    function () const;

    function_sequence&
    function ();

    void
    function (const function_sequence& s);

    // Constructors.
    //
    functions ();

    functions (const ::xercesc::DOMElement& e,
               ::xml_schema::flags f = 0,
               ::xml_schema::container* c = 0);

    functions (const functions& x,
               ::xml_schema::flags f = 0,
               ::xml_schema::container* c = 0);

    virtual functions*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~functions ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    function_sequence function_;
  };

  class QDUGraph: public ::xml_schema::type
  {
    public:
    // channel
    // 
    typedef ::q2profiling::ChannelType channel_type;
    typedef ::xsd::cxx::tree::sequence< channel_type > channel_sequence;
    typedef channel_sequence::iterator channel_iterator;
    typedef channel_sequence::const_iterator channel_const_iterator;
    typedef ::xsd::cxx::tree::traits< channel_type, char > channel_traits;

    const channel_sequence&
    channel () const;

    channel_sequence&
    channel ();

    void
    channel (const channel_sequence& s);

    // Constructors.
    //
    QDUGraph ();

    QDUGraph (const ::xercesc::DOMElement& e,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    QDUGraph (const QDUGraph& x,
              ::xml_schema::flags f = 0,
              ::xml_schema::container* c = 0);

    virtual QDUGraph*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~QDUGraph ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    channel_sequence channel_;
  };

  class CallGraph: public ::xml_schema::type
  {
    public:
    // call
    // 
    typedef ::q2profiling::CallType call_type;
    typedef ::xsd::cxx::tree::sequence< call_type > call_sequence;
    typedef call_sequence::iterator call_iterator;
    typedef call_sequence::const_iterator call_const_iterator;
    typedef ::xsd::cxx::tree::traits< call_type, char > call_traits;

    const call_sequence&
    call () const;

    call_sequence&
    call ();

    void
    call (const call_sequence& s);

    // Constructors.
    //
    CallGraph ();

    CallGraph (const ::xercesc::DOMElement& e,
               ::xml_schema::flags f = 0,
               ::xml_schema::container* c = 0);

    CallGraph (const CallGraph& x,
               ::xml_schema::flags f = 0,
               ::xml_schema::container* c = 0);

    virtual CallGraph*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    virtual 
    ~CallGraph ();

    // Implementation.
    //
    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    call_sequence call_;
  };
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace q2profiling
{
  // Parse a URI or a local file.
  //

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (const ::std::string& uri,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (const ::std::string& uri,
            ::xml_schema::error_handler& eh,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (const ::std::string& uri,
            ::xercesc::DOMErrorHandler& eh,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());

  // Parse std::istream.
  //

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (::std::istream& is,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (::std::istream& is,
            ::xml_schema::error_handler& eh,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (::std::istream& is,
            ::xercesc::DOMErrorHandler& eh,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (::std::istream& is,
            const ::std::string& id,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (::std::istream& is,
            const ::std::string& id,
            ::xml_schema::error_handler& eh,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (::std::istream& is,
            const ::std::string& id,
            ::xercesc::DOMErrorHandler& eh,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());

  // Parse xercesc::InputSource.
  //

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (::xercesc::InputSource& is,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (::xercesc::InputSource& is,
            ::xml_schema::error_handler& eh,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (::xercesc::InputSource& is,
            ::xercesc::DOMErrorHandler& eh,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());

  // Parse xercesc::DOMDocument.
  //

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (const ::xercesc::DOMDocument& d,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());

  ::std::auto_ptr< ::q2profiling::ProfilesType >
  profiles (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >& d,
            ::xml_schema::flags f = 0,
            const ::xml_schema::properties& p = ::xml_schema::properties ());
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // Q2PROFILING_HXX
