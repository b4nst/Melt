// ABLETON
#include "src/ableton/alsableton.h"
#include "src/ableton/alsliveset.h"

// IO
#include "src/io/alsfilestreambase.h"

M_NAMESPACE_ABLETON_BEGIN


AlsAbleton::AlsAbleton()
: LiveSet(nullptr)
{
  _classManipulator = decltype(_classManipulator){
      { "LiveSet", qMakePair(static_cast<CreateVarLambda>(&AlsAbleton::createLiveSet), nullptr) },
      { "MajorVersion", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsAbleton::setMajorVersion)) },
      { "MinorVersion", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsAbleton::setMinorVersion)) },
      { "SchemaChangeCount", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsAbleton::setSchemaChangeCount)) },
      { "Creator", qMakePair(nullptr, static_cast<SetVarLambda>(&AlsAbleton::setCreator)) }
  };

  _tagName = "Ableton";
}

QSharedPointer<QObject> AlsAbleton::createLiveSet()
{
  LiveSet = QSharedPointer<AlsLiveSet>(new AlsLiveSet());
  return LiveSet.staticCast<QObject>();
}

void AlsAbleton::setMajorVersion(const QString &r_value)
{
  MajorVersion = r_value;
}

void AlsAbleton::setMinorVersion(const QString &r_value)
{
  MinorVersion = r_value;
}

void AlsAbleton::setSchemaChangeCount(const QString &r_value)
{
  SchemaChangeCount = r_value.toInt();
}

void AlsAbleton::setCreator(const QString &r_value)
{
  Creator = r_value;
}

void AlsAbleton::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  p_fos_->write("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");

  QList<QPair<QString,QString>> attributes = {
    {"MajorVersion", MajorVersion},
    {"MinorVerion", MinorVersion},
    {"SchemaChangeCount", QString::number(SchemaChangeCount)},
    {"Creator", Creator}
  };

  writeStartTag(p_fos_,_tagName,attributes,r_indentLvl_);
  ++r_indentLvl_;
  LiveSet->write(p_fos_,r_indentLvl_);
  --r_indentLvl_;
  writeEndTag(p_fos_, _tagName, r_indentLvl_);
}

AlsAbleton::~AlsAbleton()
{
  LiveSet.clear();
}


M_NAMESPACE_ABLETON_END
