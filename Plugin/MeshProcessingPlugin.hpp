#pragma once

#include <Core/CoreMacros.hpp>
/// Defines the correct macro to export dll symbols.
#if defined MeshProcessingPlugin_EXPORTS
#define MeshProcessingPlugin_API DLL_EXPORT
#else
#define MeshProcessingPlugin_API DLL_IMPORT
#endif

#include <PluginBase/RadiumPluginInterface.hpp>
#include <widget.hpp>

namespace RadiumMeshProcessing {

/**
 * This plugin just call the example library when initialized.
 */
class MeshProcessingPlugin_API MeshProcessingPlugin
    : public QObject,
      Ra::Plugins::RadiumPluginInterface {
  Q_OBJECT
  Q_RADIUM_PLUGIN_METADATA
  Q_INTERFACES(Ra::Plugins::RadiumPluginInterface)

public:
  MeshProcessingPlugin() = default;

  ~MeshProcessingPlugin() override = default;

  void registerPlugin(const Ra::Plugins::Context &context) override;

  bool doAddWidget(QString &name) override;
  QWidget *getWidget() override;
  bool doAddMenu() override { return false; }
  QMenu *getMenu() override { return nullptr; }
  bool doAddAction(int &nb) override { return false; }
  QAction *getAction(int id) override { return nullptr; }

  bool doAddRenderer() override { return false; }
  void
  addRenderers(std::vector<std::shared_ptr<Ra::Engine::Rendering::Renderer>> *)
      override {}

  virtual bool doAddFileLoader() { return false; }
  virtual void addFileLoaders(
      std::vector<std::shared_ptr<Ra::Core::Asset::FileLoaderInterface>> *) {}

  virtual bool doAddROpenGLInitializer() { return false; }
  virtual void openGlInitialize(const Ra::Plugins::Context &) {}

signals:
  void askForUpdate();

private:
  Ra::Engine::RadiumEngine *m_engine{nullptr};
  Ra::Gui::SelectionManager *m_selectionManager{nullptr};
  RadiumMeshProcessing::MyWidget *m_widget{nullptr};
};

} // namespace RadiumMeshProcessing
