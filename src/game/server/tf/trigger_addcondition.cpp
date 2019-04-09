#include "cbase.h"
#include "triggers.h"
#include "tf_player.h"

class CTriggerAddTFPlayerCondition : public CBaseTrigger
{
	DECLARE_CLASS( CTriggerAddTFPlayerCondition, CBaseTrigger );

public:
	void	Spawn( void );
	void	StartTouch( CBaseEntity *pOther );
	void	EndTouch( CBaseEntity *pOther );

private:
	DECLARE_DATADESC();

	int m_nCondition;
	float m_flDuration;
};

BEGIN_DATADESC( CTriggerAddTFPlayerCondition )

	DEFINE_FIELD_NAME( m_nCondition, "condition", FIELD_INTEGER ),
	DEFINE_FIELD_NAME( m_flDuration, "duration", FIELD_FLOAT ),

	DEFINE_ENTITYFUNC( StartTouch ),
	DEFINE_ENTITYFUNC( EndTouch ),

END_DATADESC()

LINK_ENTITY_TO_CLASS( trigger_add_tf_player_condition, CTriggerAddTFPlayerCondition );


//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void CTriggerAddTFPlayerCondition::Spawn( void )
{
	BaseClass::Spawn();
	InitTrigger();
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void CTriggerAddTFPlayerCondition::StartTouch( CBaseEntity *pOther )
{
	CTFPlayer *pPlayer = ToTFPlayer( pOther );
	if ( !m_bDisabled && PassesTriggerFilters( pOther ) && pPlayer )
	{
		if ( m_nCondition == -1 )
		{
			Warning( "Invalid Condition ID[-1] in trigger %s\n", GetClassname() );
		}
		else
		{
			pPlayer->m_Shared.AddCond( m_nCondition, m_flDuration );
		}
	}
}

//-----------------------------------------------------------------------------
// Purpose:
//-----------------------------------------------------------------------------
void CTriggerAddTFPlayerCondition::EndTouch( CBaseEntity *pOther )
{
	CTFPlayer *pPlayer = ToTFPlayer( pOther );
	if ( !m_bDisabled && PassesTriggerFilters( pOther ) && pPlayer )
	{
		if ( m_nCondition == -1 )
		{
			Warning( "Invalid Condition ID[-1] in trigger %s\n", GetClassname() );
		}
		else
		{
			pPlayer->m_Shared.AddCond( m_nCondition, m_flDuration );
		}
	}
}