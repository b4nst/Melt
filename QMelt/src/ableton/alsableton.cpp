// ABLETON
#include "src/ableton/alsableton.h"
#include "src/ableton/alsliveset.h"


M_NAMESPACE_ABLETON_BEGIN


AlsAbleton::AlsAbleton()
: _liveSet(nullptr)
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
  _liveSet = QSharedPointer<AlsLiveSet>(new AlsLiveSet());
  return _liveSet.staticCast<QObject>();
}

void AlsAbleton::setMajorVersion(const QString &r_value)
{
  _majorVersion = r_value;
}

void AlsAbleton::setMinorVersion(const QString &r_value)
{
  _minorVersion = r_value;
}

void AlsAbleton::setSchemaChangeCount(const QString &r_value)
{
  _schemaChangeCount = r_value.toInt();
}

void AlsAbleton::setCreator(const QString &r_value)
{
  _creator = r_value;
}

void AlsAbleton::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)
{
  //TODO implements method write
}

AlsAbleton::~AlsAbleton()
{
  _liveSet.clear();
}


M_NAMESPACE_ABLETON_END
