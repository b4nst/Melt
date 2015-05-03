#pragma once

#include <QHash>

// parser

#include "src/parser/xmlcontext.h"


namespace parser
{


/// <summary>
/// Class XMLContentHandler
/// <para>Abstract base class for content handler (where callback startTag, inlineTag, endTag, characters are defined)</para>
/// </summary>
class XMLContentHandler
{
public:
  /// <summary>
  /// Destructor
  /// </summary>
  virtual ~XMLContentHandler();


  /// <summary>
  /// Callback method, called when the document start tag is reached by the <see cref="CoreXMLParser"/>.
  /// </summary>
  /// <param name="r_ctx_">Reference to the context.</param>
  /// <param name="version_">The version of the document.</param>
  /// <param name="encoding_">The encoding format.</param>
  virtual void startDocument(XMLContext& r_ctx_, const QString& version_, const QString& encoding_) = 0;


  /// <summary>
  /// Callback method, called when a start tag (e.g. &lt;start&gt;) is reached by the <see cref="CoreXMLParser" />.
  /// </summary>
  /// <param name="r_ctx_">Reference to the context.</param>
  /// <param name="tagName_">The tag name.</param>
  /// <param name="r_attributes_">The attributes.</param>
  /// <param name="r_line_">The raw line readed.</param>
  virtual void startTag(XMLContext& r_ctx_,const QString& r_tagName_,
                        const QHash<QString, QString>& r_attributes_,
                        const QString& r_line_) = 0;


  /// <summary>
  /// Callback method, called when an inline tag (e.g. &lt;inline/&gt;) is reached by the <see cref="CoreXMLParser" />.
  /// </summary>
  /// <param name="r_ctx_">Reference to the context.</param>
  /// <param name="tagName_">The tag name</param>
  /// <param name="r_attributes_">The attributes</param>
  /// <param name="r_line_">The raw line readed.</param>
  virtual void inlineTag(XMLContext& r_ctx_, const QString& r_tagName_,
                         const QHash<QString, QString>& r_attributes_,
                         const QString& r_line_) = 0;


  /// <summary>
  /// Callback method, called when an inline tag (e.g. &lt;/end&gt;) is reached by the <see cref="CoreXMLParser" />.
  /// </summary>
  /// <param name="r_ctx_">Reference to the context.</param>
  /// <param name="r_tagName_">The r_tag name_.</param>
  /// <param name="r_line_">The raw line readed.</param>
  virtual void endTag(XMLContext& r_ctx_, const QString& r_tagName_,
                      const QString& r_line_) = 0;


  /// <summary>
  /// Callback method, called when outside of tag character are reached by the <see cref="CoreXMLParser"/>.
  /// Good way to process this datas is to buffer them until the next endtag is reached.
  /// </summary>
  /// <param name="r_ctx">Reference to the context</param>
  /// <param name="r_data">The characters</param>
  virtual void characters(XMLContext& r_ctx, const QString& r_data_);


protected:
  /// <summary>
  /// Constructor
  /// </summary>
  XMLContentHandler();
};


} // namespace parser

