#include <KlayGE/KlayGE.hpp>

#include "MtlEditorCore.hpp"
#include "Commands.hpp"

using namespace std;
using namespace KlayGE;

namespace KlayGE
{
	char const * editor_command_name[ECC_NumCommands] =
	{
		"Set current frame",
		"Select mesh",
		"Set ambient",
		"Set diffuse",
		"Set specular",
		"Set shininess",
		"Set emit",
		"Set opacity",
		"Set diffuse texture",
		"Set specular texture",
		"Set shininess texture",
		"Set normal texture",
		"Set height texture",
		"Set emit texture",
		"Set opacity texture"
	};


	MtlEditorCommand::MtlEditorCommand(MtlEditorCore* core)
		: core_(core)
	{
	}


	MtlEditorCommandSetCurrFrame::MtlEditorCommandSetCurrFrame(MtlEditorCore* core, float frame)
		: MtlEditorCommandConcrete<ECC_SetCurrFrame>(core), frame_(frame), old_frame_()
	{
	}

	void MtlEditorCommandSetCurrFrame::Execute()
	{
		old_frame_ = core_->CurrFrame();
		core_->CurrFrame(frame_);
	}

	void MtlEditorCommandSetCurrFrame::Revoke()
	{
		core_->CurrFrame(old_frame_);
	}
	
	
	MtlEditorCommandSelectMesh::MtlEditorCommandSelectMesh(MtlEditorCore* core, uint32_t mesh_id)
		: MtlEditorCommandConcrete<ECC_SelectMesh>(core), mesh_id_(mesh_id), old_mesh_id_()
	{
	}

	void MtlEditorCommandSelectMesh::Execute()
	{
		old_mesh_id_ = core_->SelectedMesh();
		core_->SelectMesh(mesh_id_);
	}

	void MtlEditorCommandSelectMesh::Revoke()
	{
		core_->SelectMesh(old_mesh_id_);
	}


	MtlEditorCommandSetAmbientMaterial::MtlEditorCommandSetAmbientMaterial(MtlEditorCore* core,
			uint32_t mtl_id, float* value)
		: MtlEditorCommandConcrete<ECC_SetAmbientMaterial>(core),
			mtl_id_(mtl_id), ambient_(value)
	{
	}

	void MtlEditorCommandSetAmbientMaterial::Execute()
	{
		old_ambient_ = core_->AmbientMaterial(mtl_id_);
		core_->AmbientMaterial(mtl_id_, ambient_);
	}

	void MtlEditorCommandSetAmbientMaterial::Revoke()
	{
		core_->AmbientMaterial(mtl_id_, old_ambient_);
	}


	MtlEditorCommandSetDiffuseMaterial::MtlEditorCommandSetDiffuseMaterial(MtlEditorCore* core,
			uint32_t mtl_id, float* value)
		: MtlEditorCommandConcrete<ECC_SetDiffuseMaterial>(core),
			mtl_id_(mtl_id), diffuse_(value)
	{
	}

	void MtlEditorCommandSetDiffuseMaterial::Execute()
	{
		old_diffuse_ = core_->DiffuseMaterial(mtl_id_);
		core_->DiffuseMaterial(mtl_id_, diffuse_);
	}

	void MtlEditorCommandSetDiffuseMaterial::Revoke()
	{
		core_->DiffuseMaterial(mtl_id_, old_diffuse_);
	}


	MtlEditorCommandSetSpecularMaterial::MtlEditorCommandSetSpecularMaterial(MtlEditorCore* core,
			uint32_t mtl_id, float* value)
		: MtlEditorCommandConcrete<ECC_SetSpecularMaterial>(core),
			mtl_id_(mtl_id), specular_(value)
	{
	}

	void MtlEditorCommandSetSpecularMaterial::Execute()
	{
		old_specular_ = core_->SpecularMaterial(mtl_id_);
		core_->SpecularMaterial(mtl_id_, specular_);
	}

	void MtlEditorCommandSetSpecularMaterial::Revoke()
	{
		core_->SpecularMaterial(mtl_id_, old_specular_);
	}


	MtlEditorCommandSetShininessMaterial::MtlEditorCommandSetShininessMaterial(MtlEditorCore* core,
			uint32_t mtl_id, float value)
		: MtlEditorCommandConcrete<ECC_SetShininessMaterial>(core),
			mtl_id_(mtl_id), shininess_(value), old_shininess_()
	{
	}

	void MtlEditorCommandSetShininessMaterial::Execute()
	{
		old_shininess_ = core_->ShininessMaterial(mtl_id_);
		core_->ShininessMaterial(mtl_id_, shininess_);
	}

	void MtlEditorCommandSetShininessMaterial::Revoke()
	{
		core_->ShininessMaterial(mtl_id_, old_shininess_);
	}


	MtlEditorCommandSetEmitMaterial::MtlEditorCommandSetEmitMaterial(MtlEditorCore* core,
			uint32_t mtl_id, float* value)
		: MtlEditorCommandConcrete<ECC_SetEmitMaterial>(core),
			mtl_id_(mtl_id), emit_(value)
	{
	}

	void MtlEditorCommandSetEmitMaterial::Execute()
	{
		old_emit_ = core_->EmitMaterial(mtl_id_);
		core_->EmitMaterial(mtl_id_, emit_);
	}

	void MtlEditorCommandSetEmitMaterial::Revoke()
	{
		core_->EmitMaterial(mtl_id_, old_emit_);
	}


	MtlEditorCommandSetOpacityMaterial::MtlEditorCommandSetOpacityMaterial(MtlEditorCore* core,
			uint32_t mtl_id, float value)
		: MtlEditorCommandConcrete<ECC_SetOpacityMaterial>(core),
			mtl_id_(mtl_id), opacity_(value), old_opacity_()
	{
	}

	void MtlEditorCommandSetOpacityMaterial::Execute()
	{
		old_opacity_ = core_->OpacityMaterial(mtl_id_);
		core_->OpacityMaterial(mtl_id_, opacity_);
	}

	void MtlEditorCommandSetOpacityMaterial::Revoke()
	{
		core_->OpacityMaterial(mtl_id_, old_opacity_);
	}


	MtlEditorCommandSetDiffuseTexture::MtlEditorCommandSetDiffuseTexture(MtlEditorCore* core,
			uint32_t mtl_id, char const * name)
		: MtlEditorCommandConcrete<ECC_SetDiffuseTexture>(core),
			mtl_id_(mtl_id), name_(name)
	{
	}

	void MtlEditorCommandSetDiffuseTexture::Execute()
	{
		old_name_ = core_->DiffuseTexture(mtl_id_);
		core_->DiffuseTexture(mtl_id_, name_.c_str());
	}

	void MtlEditorCommandSetDiffuseTexture::Revoke()
	{
		core_->DiffuseTexture(mtl_id_, old_name_.c_str());
	}


	MtlEditorCommandSetSpecularTexture::MtlEditorCommandSetSpecularTexture(MtlEditorCore* core,
			uint32_t mtl_id, char const * name)
		: MtlEditorCommandConcrete<ECC_SetSpecularTexture>(core),
			mtl_id_(mtl_id), name_(name)
	{
	}

	void MtlEditorCommandSetSpecularTexture::Execute()
	{
		old_name_ = core_->SpecularTexture(mtl_id_);
		core_->SpecularTexture(mtl_id_, name_.c_str());
	}

	void MtlEditorCommandSetSpecularTexture::Revoke()
	{
		core_->SpecularTexture(mtl_id_, old_name_.c_str());
	}


	MtlEditorCommandSetShininessTexture::MtlEditorCommandSetShininessTexture(MtlEditorCore* core,
			uint32_t mtl_id, char const * name)
		: MtlEditorCommandConcrete<ECC_SetShininessTexture>(core),
			mtl_id_(mtl_id), name_(name)
	{
	}

	void MtlEditorCommandSetShininessTexture::Execute()
	{
		old_name_ = core_->ShininessTexture(mtl_id_);
		core_->ShininessTexture(mtl_id_, name_.c_str());
	}

	void MtlEditorCommandSetShininessTexture::Revoke()
	{
		core_->ShininessTexture(mtl_id_, old_name_.c_str());
	}


	MtlEditorCommandSetNormalTexture::MtlEditorCommandSetNormalTexture(MtlEditorCore* core,
			uint32_t mtl_id, char const * name)
		: MtlEditorCommandConcrete<ECC_SetNormalTexture>(core),
			mtl_id_(mtl_id), name_(name)
	{
	}

	void MtlEditorCommandSetNormalTexture::Execute()
	{
		old_name_ = core_->NormalTexture(mtl_id_);
		core_->NormalTexture(mtl_id_, name_.c_str());
	}

	void MtlEditorCommandSetNormalTexture::Revoke()
	{
		core_->NormalTexture(mtl_id_, old_name_.c_str());
	}


	MtlEditorCommandSetHeightTexture::MtlEditorCommandSetHeightTexture(MtlEditorCore* core,
			uint32_t mtl_id, char const * name)
		: MtlEditorCommandConcrete<ECC_SetHeightTexture>(core),
			mtl_id_(mtl_id), name_(name)
	{
	}

	void MtlEditorCommandSetHeightTexture::Execute()
	{
		old_name_ = core_->HeightTexture(mtl_id_);
		core_->HeightTexture(mtl_id_, name_.c_str());
	}

	void MtlEditorCommandSetHeightTexture::Revoke()
	{
		core_->HeightTexture(mtl_id_, old_name_.c_str());
	}


	MtlEditorCommandSetEmitTexture::MtlEditorCommandSetEmitTexture(MtlEditorCore* core,
			uint32_t mtl_id, char const * name)
		: MtlEditorCommandConcrete<ECC_SetEmitTexture>(core),
			mtl_id_(mtl_id), name_(name)
	{
	}

	void MtlEditorCommandSetEmitTexture::Execute()
	{
		old_name_ = core_->EmitTexture(mtl_id_);
		core_->EmitTexture(mtl_id_, name_.c_str());
	}

	void MtlEditorCommandSetEmitTexture::Revoke()
	{
		core_->EmitTexture(mtl_id_, old_name_.c_str());
	}


	MtlEditorCommandSetOpacityTexture::MtlEditorCommandSetOpacityTexture(MtlEditorCore* core,
			uint32_t mtl_id, char const * name)
		: MtlEditorCommandConcrete<ECC_SetOpacityTexture>(core),
			mtl_id_(mtl_id), name_(name)
	{
	}

	void MtlEditorCommandSetOpacityTexture::Execute()
	{
		old_name_ = core_->OpacityTexture(mtl_id_);
		core_->OpacityTexture(mtl_id_, name_.c_str());
	}

	void MtlEditorCommandSetOpacityTexture::Revoke()
	{
		core_->OpacityTexture(mtl_id_, old_name_.c_str());
	}
}
