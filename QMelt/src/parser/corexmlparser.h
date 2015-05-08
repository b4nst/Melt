#pragma once

#include <QHash>

// parser

#include "src/parser/xmlcontenthandler.h"


//forward declaration
namespace io { class AlsFileStreamBase; }


namespace parser
{


/// <summary>
/// Class CoreXMLParser.
/// <para>
/// Parse a XML file/stream with SAX algorithm
/// </para>
/// </summary>
class CoreXMLParser
{
public:
  CoreXMLParser(){}
  ~CoreXMLParser(){}

  /// <summary>
  /// Parses the specified stream.
  /// </summary>
  /// <param name="p_stream_">The stream to parse from.</param>
  /// <param name="r_handler_">The handler (containing callback methods).</param>
  /// <param name="r_ctx_">The context.</param>
  void parse(QSharedPointer<io::AlsFileStreamBase> p_stream_,
    XMLContentHandler& r_handler_, XMLContext& r_ctx_);

private:
  /// <summary>
  /// Finds the arguments in str_.
  /// </summary>
  /// <param name="str_">The string to find in.</param>
  /// <param name="args_">The arguments found</param>
  void findArgs(QString  str_, QHash<QString, QString>& args_);
};


} // namespace parser
