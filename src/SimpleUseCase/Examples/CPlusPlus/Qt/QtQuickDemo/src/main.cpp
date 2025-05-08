#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc,char* argv[])
{
  int result = 0;

  {
    QGuiApplication app(argc,argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/QtQuickDemo.qml"));
    if(!engine.rootObjects().isEmpty())
    {
      result = app.exec();
    }
  }

  return result;
}
