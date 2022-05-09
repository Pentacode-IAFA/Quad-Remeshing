#include "ui_widget.h"
#include <widget.hpp>

#include <QComboBox>

#include <Engine/Data/Mesh.hpp>
#include <Engine/Scene/Component.hpp>
#include <Engine/Scene/Entity.hpp>
#include <Gui/SelectionManager/SelectionManager.hpp>

namespace QuadRemeshing {

static const QString separator = "_";

MyWidget::MyWidget(Ra::Engine::RadiumEngine *engine,
                   Ra::Gui::SelectionManager *selectionManager, QWidget *parent)
    : QWidget(parent),
      ui(new Ui::MyWidget), m_engine{engine}, m_selectionManager{
                                                  selectionManager} {
  ui->setupUi(this);
  m_remesher = new QuadRemeshing::QuadRemesher();
}

MyWidget::~MyWidget() { delete ui; }

void MyWidget::on__remeshButton_clicked() {
  LOG(Ra::Core::Utils::logINFO) << "Starting remesh";
}
void MyWidget::on__step1Button_clicked() {
  LOG(Ra::Core::Utils::logINFO) << "Starting Step 1";
  m_remesher->step1();
}
void MyWidget::on__step2Button_clicked() {
  LOG(Ra::Core::Utils::logINFO) << "Starting Step 2";
  m_remesher->step2();
}
void MyWidget::on__step3Button_clicked() {
  LOG(Ra::Core::Utils::logINFO) << "Starting Step 3";
  auto mesh = getSelectedMesh();

  if (mesh) {
    m_remesher->setMesh(mesh);
    m_remesher->step3();
  } else {
    LOG(Ra::Core::Utils::logINFO) << "WARNING: no mesh selected";
  }
}
void MyWidget::on__step4Button_clicked() {
  LOG(Ra::Core::Utils::logINFO) << "Starting Step 4";
  m_remesher->step4();
}
void MyWidget::on__step5Button_clicked() {
  LOG(Ra::Core::Utils::logINFO) << "Starting Step 5";
  m_remesher->step5();
}

Ra::Engine::Data::Mesh *MyWidget::getSelectedMesh() {

  // using Ra::Core::Geometry::TopologicalMesh;
  // using Ra::Engine::Data::Mesh;
  // using Ra::Engine::Data::PolyMesh;

  auto objectsToProcess = m_selectionManager->selectedEntries();
  for (const auto &toProcess : objectsToProcess) {
    if (!(toProcess.isComponentNode() || toProcess.isRoNode())) {
      LOG(Ra::Core::Utils::logWARNING)
          << "quad processing only available for selected components or "
             "renderobjects.";
      continue;
    }

    std::string entityName = toProcess.m_entity->getName();
    std::string componentName = toProcess.m_component->getName();

    auto trianglemesh = dynamic_cast<Ra::Engine::Data::Mesh *>(
        Ra::Engine::RadiumEngine::getInstance()->getMesh(entityName,
                                                         componentName));

    if (trianglemesh)
      return trianglemesh;
  }

  return nullptr;
}

} // namespace QuadRemeshing
