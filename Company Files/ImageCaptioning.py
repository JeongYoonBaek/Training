import torch
from diffusers import FluxPipeline

# FLUX.1-dev 모델 불러오기
pipe = FluxPipeline.from_pretrained("black-forest-labs/FLUX.1-dev", torch_dtype=torch.bfloat16)

# 모델을 CPU로 오프로딩하여 VRAM 절약 (옵션)
pipe.enable_model_cpu_offload()
