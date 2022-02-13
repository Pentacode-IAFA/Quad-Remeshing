#include "ui_widget.h"
#include <widget.hpp>

#include <QComboBox>

#include <Engine/Scene/Component.hpp>
#include <Engine/Scene/Entity.hpp>
#include <Gui/SelectionManager/SelectionManager.hpp>

namespace RadiumMeshProcessing {

static const QString separator = "_";

MyWidget::MyWidget(Ra::Engine::RadiumEngine *engine,
                   Ra::Gui::SelectionManager *selectionManager, QWidget *parent)
    : QWidget(parent),
      ui(new Ui::MyWidget), m_engine{engine}, m_selectionManager{
                                                  selectionManager} {
  ui->setupUi(this);
}

MyWidget::~MyWidget() { delete ui; }

void MyWidget::on__runButton_clicked() {
  auto objectsToProcess = m_selectionManager->selectedEntries();
  for (const auto &toProcess : objectsToProcess) {
    if (!(toProcess.isComponentNode() || toProcess.isRoNode())) {
      LOG(Ra::Core::Utils::logWARNING)
          << "Laplacian processing only available for selected components or "
             "renderobjects.";
      continue;
    }
    // toProcess is a component, call laplacianSmoothing on it
    ProcessingParameter p;
    p.entityName = toProcess.m_entity->getName();
    p.componentName = toProcess.m_component->getName();
    emit computationRequested(p);
  }
}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
void MyWidget::on__customButton_clicked() { emit customRequest(5); }

} // namespace RadiumMeshProcessing
