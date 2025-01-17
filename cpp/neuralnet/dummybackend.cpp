#include "../neuralnet/nninterface.h"
#include "../neuralnet/nninputs.h"

using namespace std;

void NeuralNet::globalInitialize() {
  // Do nothing, calling this is okay even if there is no neural net
  // as long as we don't attempt to actually load a net file and use one.
}

void NeuralNet::globalCleanup() {
  // Do nothing, calling this is okay even if there is no neural net
  // as long as we don't attempt to actually load a net file and use one.
}

ComputeContext* NeuralNet::createComputeContext(
  const std::vector<int>& gpuIdxs,
  Logger* logger,
  int nnXLen,
  int nnYLen,
  string openCLTunerFile,
  const LoadedModel* loadedModel
) {
  (void)gpuIdxs;
  (void)logger;
  (void)nnXLen;
  (void)nnYLen;
  (void)openCLTunerFile;
  (void)loadedModel;
  throw StringError("Dummy neural net backend: NeuralNet::createComputeContext unimplemented");
}
void NeuralNet::freeComputeContext(ComputeContext* computeContext) {
  (void)computeContext;
  throw StringError("Dummy neural net backend: NeuralNet::freeComputeContext unimplemented");
}

LoadedModel* NeuralNet::loadModelFile(const string& file, int modelFileIdx) {
  (void)file;
  (void)modelFileIdx;
  throw StringError("Dummy neural net backend: NeuralNet::loadModelFile unimplemented");
}

void NeuralNet::freeLoadedModel(LoadedModel* loadedModel) {
  (void)loadedModel;
  throw StringError("Dummy neural net backend: NeuralNet::freeLoadedModel unimplemented");
}

int NeuralNet::getModelVersion(const LoadedModel* loadedModel) {
  (void)loadedModel;
  throw StringError("Dummy neural net backend: NeuralNet::getModelVersion unimplemented");
}

Rules NeuralNet::getSupportedRules(const LoadedModel* loadedModel, const Rules& desiredRules, bool& supported) {
  (void)loadedModel;
  (void)desiredRules;
  (void)supported;
  throw StringError("Dummy neural net backend: NeuralNet::getSupportedRules unimplemented");
}

ComputeHandle* NeuralNet::createComputeHandle(
  ComputeContext* context,
  const LoadedModel* loadedModel,
  Logger* logger,
  int maxBatchSize,
  int nnXLen,
  int nnYLen,
  bool requireExactNNLen,
  bool inputsUseNHWC,
  int gpuIdxForThisThread,
  bool useFP16,
  bool useNHWC
) {
  (void)context;
  (void)loadedModel;
  (void)logger;
  (void)maxBatchSize;
  (void)nnXLen;
  (void)nnYLen;
  (void)requireExactNNLen;
  (void)inputsUseNHWC;
  (void)gpuIdxForThisThread;
  (void)useFP16;
  (void)useNHWC;
  throw StringError("Dummy neural net backend: NeuralNet::createLocalGpuHandle unimplemented");
}

void NeuralNet::freeComputeHandle(ComputeHandle* gpuHandle) {
  if(gpuHandle != NULL)
    throw StringError("Dummy neural net backend: NeuralNet::freeLocalGpuHandle unimplemented");
}

InputBuffers* NeuralNet::createInputBuffers(const LoadedModel* loadedModel, int maxBatchSize, int nnXLen, int nnYLen) {
  (void)loadedModel;
  (void)maxBatchSize;
  (void)nnXLen;
  (void)nnYLen;
  throw StringError("Dummy neural net backend: NeuralNet::createInputBuffers unimplemented");
}

void NeuralNet::freeInputBuffers(InputBuffers* buffers) {
  if(buffers != NULL)
    throw StringError("Dummy neural net backend: NeuralNet::freeInputBuffers unimplemented");
}

float* NeuralNet::getBatchEltSpatialInplace(InputBuffers* buffers, int nIdx) {
  (void)buffers;
  (void)nIdx;
  throw StringError("Dummy neural net backend: NeuralNet::getBatchEltSpatialInplace unimplemented");
}

float* NeuralNet::getBatchEltGlobalInplace(InputBuffers* buffers, int nIdx) {
  (void)buffers;
  (void)nIdx;
  throw StringError("Dummy neural net backend: NeuralNet::getBatchEltGlobalInplace unimplemented");
}

bool* NeuralNet::getSymmetriesInplace(InputBuffers* buffers) {
  (void)buffers;
  throw StringError("Dummy neural net backend: NeuralNet::getSymmetriesInplace unimplemented");
}

int NeuralNet::getBatchEltSpatialLen(const InputBuffers* buffers) {
  (void)buffers;
  throw StringError("Dummy neural net backend: NeuralNet::getBatchEltSpatialLen unimplemented");
}

int NeuralNet::getBatchEltGlobalLen(const InputBuffers* buffers) {
  (void)buffers;
  throw StringError("Dummy neural net backend: NeuralNet::getBatchEltGlobalLen unimplemented");
}

void NeuralNet::getOutput(
  ComputeHandle* gpuHandle,
  InputBuffers* buffers,
  int numBatchEltsFilled,
  vector<NNOutput*>& outputs
) {
  (void)gpuHandle;
  (void)buffers;
  (void)numBatchEltsFilled;
  (void)outputs;
  throw StringError("Dummy neural net backend: NeuralNet::getOutput unimplemented");
}



bool NeuralNet::testEvaluateConv(
  const ConvLayerDesc* desc,
  int batchSize,
  int nnXLen,
  int nnYLen,
  bool useFP16,
  bool useNHWC,
  const std::vector<float>& inputBuffer,
  std::vector<float>& outputBuffer
) {
  (void)desc;
  (void)batchSize;
  (void)nnXLen;
  (void)nnYLen;
  (void)useFP16;
  (void)useNHWC;
  (void)inputBuffer;
  (void)outputBuffer;
  return false;
}

//Mask should be in 'NHW' format (no "C" channel).
bool NeuralNet::testEvaluateBatchNorm(
  const BatchNormLayerDesc* desc,
  int batchSize,
  int nnXLen,
  int nnYLen,
  bool useFP16,
  bool useNHWC,
  const std::vector<float>& inputBuffer,
  const std::vector<float>& maskBuffer,
  std::vector<float>& outputBuffer
) {
  (void)desc;
  (void)batchSize;
  (void)nnXLen;
  (void)nnYLen;
  (void)useFP16;
  (void)useNHWC;
  (void)inputBuffer;
  (void)maskBuffer;
  (void)outputBuffer;
  return false;
}

bool NeuralNet::testEvaluateResidualBlock(
  const ResidualBlockDesc* desc,
  int batchSize,
  int nnXLen,
  int nnYLen,
  bool useFP16,
  bool useNHWC,
  const std::vector<float>& inputBuffer,
  const std::vector<float>& maskBuffer,
  std::vector<float>& outputBuffer
) {
  (void)desc;
  (void)batchSize;
  (void)nnXLen;
  (void)nnYLen;
  (void)useFP16;
  (void)useNHWC;
  (void)inputBuffer;
  (void)maskBuffer;
  (void)outputBuffer;
  return false;
}

bool NeuralNet::testEvaluateGlobalPoolingResidualBlock(
  const GlobalPoolingResidualBlockDesc* desc,
  int batchSize,
  int nnXLen,
  int nnYLen,
  bool useFP16,
  bool useNHWC,
  const std::vector<float>& inputBuffer,
  const std::vector<float>& maskBuffer,
  std::vector<float>& outputBuffer
) {
  (void)desc;
  (void)batchSize;
  (void)nnXLen;
  (void)nnYLen;
  (void)useFP16;
  (void)useNHWC;
  (void)inputBuffer;
  (void)maskBuffer;
  (void)outputBuffer;
  return false;
}

bool NeuralNet::testEvaluateSymmetry(
  int batchSize,
  int numChannels,
  int nnXLen,
  int nnYLen,
  bool useFP16,
  bool useNHWC,
  const bool* symmetriesBuffer,
  const std::vector<float>& inputBuffer,
  std::vector<float>& outputBuffer
) {
  (void)batchSize;
  (void)numChannels;
  (void)nnXLen;
  (void)nnYLen;
  (void)useFP16;
  (void)useNHWC;
  (void)symmetriesBuffer;
  (void)inputBuffer;
  (void)outputBuffer;
  return false;
}
