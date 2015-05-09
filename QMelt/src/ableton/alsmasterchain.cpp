// ABLETON
#include "src/ableton/alsmasterchain.h"

M_NAMESPACE_ABLETON_BEGIN


AlsMasterChain::AlsMasterChain(QObject *parent)
: AbletonObject(parent)
{
  _tagName = "MasterChain";
}

void AlsMasterChain::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, QList<QPair<QString,QString>>(), r_indentLvl_);
  writeGarbage(p_fos_);
  writeEndTag(p_fos_, _tagName, r_indentLvl_);
}

AlsMasterChain::~AlsMasterChain()
{

}


M_NAMESPACE_ABLETON_END
