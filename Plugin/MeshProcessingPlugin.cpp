#include <MeshProcessingPlugin.hpp>

#include <Gui/Viewer/Viewer.hpp>
namespace RadiumMeshProcessing {

void MeshProcessingPlugin::registerPlugin(const Ra::Plugins::Context &context) {
  m_engine = context.m_engine;
  m_selectionManager = context.m_selectionManager;

  connect(this, &MeshProcessingPlugin::askForUpdate, &context,
          &Ra::Plugins::Context::askForUpdate);
  RadiumMeshProcessing::RadiumMeshProcessingWelcome(
      "Initializing RadiumMeshProcessing library.");
  RadiumMeshProcessing::initializeRadiumMeshProcessing();
  RadiumMeshProcessing::RadiumMeshProcessingWelcome("Registering plugin.");
}
bool MeshProcessingPlugin::doAddWidget(QString &name) {
  name = "Mesh Processing";
  m_widget = new MyWidget(m_engine, m_selectionManager);

  connect(m_widget, &MyWidget::computationRequested,
          [this](ProcessingParameter p) {
            RadiumMeshProcessing::LaplacianSmoothing(p);
            emit askForUpdate();
          });

  // <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
  connect(m_widget, &MyWidget::customRequest, [this](int value) {
    RadiumMeshProcessing::customFonction(value);
    emit askForUpdate();
  });

  return true;
}
QWidget *MeshProcessingPlugin::getWidget() { return m_widget; }
} // namespace RadiumMeshProcessing
