#include "ui_widget.h"
#include <widget.hpp>

#include <QComboBox>

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
}

MyWidget::~MyWidget() { delete ui; }

void MyWidget::on__remeshButton_clicked() {
  LOG(Ra::Core::Utils::logINFO) << "Starting remesh";
}
void MyWidget::on__step1Button_clicked() {
  LOG(Ra::Core::Utils::logINFO) << "Starting Step 1";
}
void MyWidget::on__step2Button_clicked() {
  LOG(Ra::Core::Utils::logINFO) << "Starting Step 2";
}
void MyWidget::on__step3Button_clicked() {
  LOG(Ra::Core::Utils::logINFO) << "Starting Step 3";
}
void MyWidget::on__step4Button_clicked() {
  LOG(Ra::Core::Utils::logINFO) << "Starting Step 4";
}
void MyWidget::on__step5Button_clicked() {
  LOG(Ra::Core::Utils::logINFO) << "Starting Step 5";
}

} // namespace QuadRemeshing
