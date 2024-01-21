#include "extdll.h"
#include "util.h"
#include "cbase.h"
#include "animation.h"


/*
============
COM_FileExtension
============
*/
const char* COM_FileExtension(const char* in)
{
	const char* separator, * backslash, * colon, * dot;

	separator = strrchr(in, '/');
	backslash = strrchr(in, '\\');

	if (!separator || separator < backslash)
		separator = backslash;

	colon = strrchr(in, ':');

	if (!separator || separator < colon)
		separator = colon;

	dot = strrchr(in, '.');

	if (dot == NULL || (separator && (dot < separator)))
		return "";

	return dot + 1;
}

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
	const char* ext = COM_FileExtension(szModel);

	if (!strcmp(ext, "bsp"))
	{
		pev->solid = SOLID_BSP;
		pev->movetype = MOVETYPE_PUSHSTEP;
	}
	else
	{
		pev->solid = SOLID_BBOX;
		pev->movetype = MOVETYPE_TOSS;
	}
	pev->classname = MAKE_STRING("point_model");
	PRECACHE_MODEL(szModel);
	SET_MODEL(ENT(pev), szModel);
}

LINK_ENTITY_TO_CLASS(point_model, CModel)