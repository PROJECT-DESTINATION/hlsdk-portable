#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "animation.h"


class CModel : public CBaseEntity
{
	void Spawn(void);
};

void CModel::Spawn()
{
	const char* szModel = STRING(pev->model);
	if (!szModel || !*szModel)
	{
		ALERT(at_error, "point_model at %.0f %.0f %0.f missing modelname", (double)pev->origin.x, (double)pev->origin.y, (double)pev->origin.z);
		REMOVE_ENTITY(ENT(pev));
		return;
	}

	pev->classname = MAKE_STRING("point_model");
	PRECACHE_MODEL(szModel);
	SET_MODEL(ENT(pev), szModel);
}

LINK_ENTITY_TO_CLASS(point_model, CModel)