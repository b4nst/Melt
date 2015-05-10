// ABLETON
#include "src/ableton/alsmastertrack.h"
#include "src/ableton/alsmasterchain.h"


M_NAMESPACE_ABLETON_BEGIN


AlsMasterTrack::AlsMasterTrack(QObject *parent)
: AlsTrack(parent)
, MasterChain(QSharedPointer<AlsMasterChain>())
{
  QHash<QString, QPair<CreateVarLambda, SetVarLambda>> manipulatorConcat =  decltype(_classManipulator){
    { "MasterChain", qMakePair(static_cast<CreateVarLambda>(&AlsMasterTrack::createMasterChain), nullptr) }
  };

  _classManipulator.unite(manipulatorConcat);
  _tagName = "MasterTrack";

}

void AlsMasterTrack::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, QList<QPair<QString,QString>>(), r_indentLvl_);
  ++r_indentLvl_;
  AlsTrack::write(p_fos_, r_indentLvl_);
  MasterChain->write(p_fos_,r_indentLvl_);
  writeGarbage(p_fos_);
  --r_indentLvl_;
  writeEndTag(p_fos_, _tagName, r_indentLvl_);
}

AlsMasterTrack::~AlsMasterTrack()
{

}

QSharedPointer<QObject> AlsMasterTrack::createMasterChain()
{
  MasterChain = QSharedPointer<AlsMasterChain>(new AlsMasterChain(this));
  return MasterChain.staticCast<QObject>();
}


M_NAMESPACE_ABLETON_END
