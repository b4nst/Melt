#pragma once
#include "src/app/meltcommon.h"


// PARSER

#include "src/parser/xmlcontenthandler.h"


// QT

#include <QHash>


M_NAMESPACE_PARSER_BEGIN
class AlsXMLContentHandler : public parser::XMLContentHandler
{
public:
  AlsXMLContentHandler(){}
  ~AlsXMLContentHandler(){}

  /// <summary>
  /// Callback method, called when the document start tag is reached by the <see cref="CoreXMLParser"/>.
  /// </summary>
  /// <param name="r_ctx_">Reference to the context.</param>
  /// <param name="version_">The version of the document.</param>
  /// <param name="encoding_">The encoding format.</param>
  void startDocument(XMLContext& r_ctx_, const QString &version_, const QString &encoding_) override;


  /// <summary>
  /// Callback method, called when a start tag (e.g. &lt;start&gt;) is reached by the <see cref="CoreXMLParser" />.
  /// </summary>
  /// <param name="r_ctx_">Reference to the context.</param>
  /// <param name="tagName_">The tag name.</param>
  /// <param name="r_attributes_">The attributes.</param>
  /// <param name="r_line_">The raw line readed.</param>
  void startTag(XMLContext& r_ctx_, const QString& r_tagName_,
    const QHash<QString, QString>& r_attributes_,
    const QString& r_line_) override;

  /// <summary>
  /// Callback method, called when an inline tag (e.g. &lt;inline/&gt;) is reached by the <see cref="CoreXMLParser" />.
  /// </summary>
  /// <param name="r_ctx_">Reference to the context.</param>
  /// <param name="tagName_">The tag name</param>
  /// <param name="r_attributes_">The attributes</param>
  /// <param name="r_line_">The raw line readed.</param>
  void inlineTag(XMLContext& r_ctx_, const QString& tagName_,
    const QHash<QString, QString>& r_attributes_,
    const QString& r_line_) override;

  /// <summary>
  /// Callback method, called when an inline tag (e.g. &lt;/end&gt;) is reached by the <see cref="CoreXMLParser" />.
  /// </summary>
  /// <param name="r_ctx_">Reference to the context.</param>
  /// <param name="r_tagName_">The r_tag name_.</param>
  /// <param name="r_line_">The raw line readed.</param>
  void endTag(XMLContext& r_ctx_, const QString& r_tagName_,
    const QString& r_line_) override;

  /// <summary>
  /// Callback method, called when outside of tag character are reached by the <see cref="CoreXMLParser"/>.
  /// Good way to process this datas is to buffer them until the next endtag is reached.
  /// </summary>
  /// <param name="r_ctx">Reference to the context</param>
  /// <param name="r_data">The characters</param>
  void characters(XMLContext& r_ctx_, const QString& r_data_) override;

private:
  bool _currTagNotProcessed;

};
M_NAMESPACE_PARSER_END

