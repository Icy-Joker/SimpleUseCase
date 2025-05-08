#include <QGuiApplication>

#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3dExtras>

int main(int argc,char* argv[])
{
  QGuiApplication app(argc,argv);

  // 创建 Qt3D 窗口
  Qt3DExtras::Qt3DWindow view;

  // 创建根实体
  if(Qt3DCore::QEntity* root_entity = new Qt3DCore::QEntity())
  {
    // 创建立方体网格
    if(Qt3DExtras::QCuboidMesh* cuboid = new Qt3DExtras::QCuboidMesh())
    {
      // 创建材质
      if(Qt3DExtras::QPhongMaterial* material = new Qt3DExtras::QPhongMaterial())
      {
        material->setDiffuse(QColor(QRgb(0x928327)));

        // 创建立方体实体并添加网格和材质
        if(Qt3DCore::QEntity* cuboid_entity = new Qt3DCore::QEntity(root_entity))
        {
          cuboid_entity->addComponent(cuboid);
          cuboid_entity->addComponent(material);
        }
      }
    }

    // 设置初始视角
    if(Qt3DRender::QCamera* camera = view.camera())
    {
      camera->lens()->setPerspectiveProjection(45.0f,16.0f / 9.0f,0.1f,1000.0f);
      camera->setPosition(QVector3D(5.0f,5.0f,5.0f));// 设置相机位置
      camera->setViewCenter(QVector3D(0.0f,0.0f,0.0f));// 设置相机看向的目标点
    }

    // 创建相机控制器
    if(Qt3DExtras::QOrbitCameraController* camera_controller = new Qt3DExtras::QOrbitCameraController(root_entity))
    {
      camera_controller->setCamera(view.camera());
      camera_controller->setLinearSpeed(1.0f);// 设置移动速度
      camera_controller->setAcceleration(0.0f);// 设置旋转加速度
      camera_controller->setZoomInLimit(1.0f);
    }

    // 设置根实体
    view.setRootEntity(root_entity);
  }

  // 显示窗口
  view.show();

  return app.exec();
}
