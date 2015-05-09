// ABLETON
#include "src/ableton/alsliveset.h"
#include "src/ableton/alsmastertrack.h"
#include "src/ableton/alsaudiotrack.h"
#include "src/ableton/alsmiditrack.h"
#include "src/ableton/alsreturntrack.h"
#include "src/ableton/alsgrouptrack.h"

// IO
#include "src/io/alsfilestreambase.h"


M_NAMESPACE_ABLETON_BEGIN

AlsLiveSet::AlsLiveSet()
: LomId(0)
, LomIdView(0)
, Overdub(false)
, MasterTrack(QSharedPointer<AlsMasterTrack>())
, Tracks(QVector<QSharedPointer<AlsTrack>>())
{
  _classManipulator = decltype(_classManipulator){
      { "LomId", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsLiveSet::setLomId)) },
      { "LomIdView", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsLiveSet::setLomIdView)) },
      { "Overdub", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsLiveSet::setOverdub)) },
      { "MasterTrack", qMakePair(static_cast<CreateVarLambda>(&AlsLiveSet::createMasterTrack), nullptr) },
      { "MidiTrack", qMakePair(static_cast<CreateVarLambda>(&AlsLiveSet::createMidiTrack), nullptr) },
      { "AudioTrack", qMakePair(static_cast<CreateVarLambda>(&AlsLiveSet::createAudioTrack), nullptr) },
      { "ReturnTrack", qMakePair(static_cast<CreateVarLambda>(&AlsLiveSet::createReturnTrack), nullptr) },
      { "GroupTrack", qMakePair(static_cast<CreateVarLambda>(&AlsLiveSet::createGroupTrack), nullptr) },
      { "Tracks", qMakePair(static_cast<CreateVarLambda>(&AlsLiveSet::createTracks), nullptr) }
  };

  _tagName = "LiveSet";

}

void AlsLiveSet::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  writeStartTag(p_fos_, _tagName, QList<QPair<QString,QString>>(), r_indentLvl_);
  ++r_indentLvl_;
  writeInlineTag(p_fos_,"LomId",{{"Value",QString::number(LomId)}},r_indentLvl_);
  writeInlineTag(p_fos_,"LomIdView",{{"Value",QString::number(LomIdView)}},r_indentLvl_);
  writeInlineTag(p_fos_,"Overdub",{{"Value",Overdub ? "true" : "false"}},r_indentLvl_);
  writeStartTag(p_fos_, "Tracks", QList<QPair<QString,QString>>(), r_indentLvl_);
  ++r_indentLvl_;
  foreach (auto trck, Tracks) {
    trck->write(p_fos_, r_indentLvl_);
  }
  --r_indentLvl_;
  writeEndTag(p_fos_,"Tracks",r_indentLvl_);
  MasterTrack->write(p_fos_,r_indentLvl_);
  p_fos_->write(_garbage);
  --r_indentLvl_;
  writeEndTag(p_fos_, _tagName, r_indentLvl_);
}

void AlsLiveSet::setLomId(const QString& value_)
{
  LomId = value_.toInt();
}

void AlsLiveSet::setLomIdView(const QString& value_)
{
  LomIdView = value_.toInt();
}

void AlsLiveSet::setOverdub(const QString& value_)
{
  QString valueToTest = value_.toLower().trimmed();
  Overdub = (valueToTest == "true" ? true : false);
}

QSharedPointer<QObject> AlsLiveSet::createMasterTrack()
{
  MasterTrack = QSharedPointer<AlsMasterTrack>(new AlsMasterTrack());
  return MasterTrack.staticCast<QObject>();
}

QSharedPointer<QObject> AlsLiveSet::createMidiTrack()
{
  QSharedPointer<AlsMidiTrack> mt = QSharedPointer<AlsMidiTrack>(new AlsMidiTrack());
  Tracks.push_back(mt);
  return mt.staticCast<QObject>();
}

QSharedPointer<QObject> AlsLiveSet::createAudioTrack()
{
  QSharedPointer<AlsAudioTrack> at = QSharedPointer<AlsAudioTrack>(new AlsAudioTrack());
  Tracks.push_back(at);
  return at.staticCast<QObject>();
}

QSharedPointer<QObject> AlsLiveSet::createReturnTrack()
{
  QSharedPointer<AlsReturnTrack> rt = QSharedPointer<AlsReturnTrack>(new AlsReturnTrack());
  Tracks.push_back(rt);
  return rt.staticCast<QObject>();
}

QSharedPointer<QObject> AlsLiveSet::createGroupTrack()
{
  QSharedPointer<AlsGroupTrack> gt = QSharedPointer<AlsGroupTrack>(new AlsGroupTrack());
  Tracks.push_back(gt);
  return gt.staticCast<QObject>();
}

QSharedPointer<QObject> AlsLiveSet::createTracks()
{
  Tracks.clear();
  return QSharedPointer<QObject>();
}

AlsLiveSet::~AlsLiveSet()
{
  MasterTrack.clear();
}


M_NAMESPACE_ABLETON_END
