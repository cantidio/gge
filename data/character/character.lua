--Arquivo de script de personagens com diretivas básicas

-- life do personagem
life				= 0
-- poder de ataque do personagem
attackPower			= 0
-- poder de defesa do personagem
defensePower		= 0
-- tempo que o personagem fica imortal depois de atingido
imortalTime			= 0
-- O número máximo de instancias de helpers
helperMaxInstances	= { }
-- Arquivos de script do helper
helperScriptFile	= { }

-- colisão acima do personagem
upColision			= {
	width	= 0,
	height	= 0,
	xOffset	= 0,
	yOffset	= 0
}
-- colisão a direita do personagem
rightColision		= {
	width	= 0,
	height	= 0,
	xOffset	= 0,
	yOffset	= 0
}
-- colisão abaixo do personagem
downColision		= {
	width	= 0,
	height	= 0,
	xOffset	= 0,
	yOffset	= 0
}
-- colisão a esquerda do personagem
leftColision		= {
	width	= 0,
	height	= 0,
	xOffset	= 0,
	yOffset	= 0
}

-- Função que retorna o número de helpers que o personagem possui
--
-- @author	Cantidio Oliveira Fontes
-- @since	13/03/2009
-- @final	13/03/2009
-- @return	int
function getHelpersNumber()
	return #helperScriptFile;
end

-- Função que retorna o número máximo de instâncias de um determinado helper
--
-- @author	Cantidio Oliveira Fontes
-- @since	13/03/2009
-- @final	13/03/2009
-- @param	int pIndex, índice do helper a verificar quantas instâncias
-- @return	int
function getHelperMaxInstances(pIndex)
	return helperMaxInstances[pIndex]
end

-- Função que retorna o arquivo de script de um determinado helper
--
-- @author	Cantidio Oliveira Fontes
-- @since	13/03/2009
-- @final	13/03/2009
-- @param	int pIndex, índice do helper a verificar o arquivo de script
-- @return	string
function getHelperScriptFile(pIndex)
	return helperScriptFile[pIndex]
end

-- Função para retornar o life do personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @return	int
function getLife()
	return lua_getLife(objectPointer)
end

-- Função para setar o life do personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @param	int pLife, life do personagem
function setLife(pLife)
	return lua_setLife(objectPointer,pLife)
end

-- Função para retirar um valor do life do personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @param	int pLife, life a ser subtraído
function subLife(pLife)
	return lua_subLife(objectPointer,pLife)
end

-- Função para adicionar um valor ao life do personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @param	int pLife, life a ser adicionado
function addLife(pLife)
	return lua_addLife(objectPointer,pLife)
end

-- Função que retorna verdadeiro se o personagem está vivo
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @return	bool
function isAlive()
	return lua_isAlive(objectPointer)
end

-- Função que ativa o personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
function ativate()
	lua_ativate(objectPointer)
end

-- Função que ativa o personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
function inativate()
	lua_inativate(objectPointer)
end

-- Função que retorna verdadeiro se o personagem está ativo
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @return	bool
function isAtive()
	return lua_isAtive(objectPointer)
end

-- Função que retorna verdadeiro se o personagem está imortal
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @return	bool
function isImortal()
	return lua_isImortal(objectPointer)
end

-- Função que machuca o personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @param	int pDamage, valor de dano recebido
function hurt(pDamage)
	return lua_hurt(objectPointer,pDamage)
end

-- Função que chama um helper do personagem
--
-- @author	Cantidio Oliveira Fontes
-- @since	12/03/2009
-- @final	12/03/2009
-- @param	int pPosX			, posição x que o helper aparecerá
-- @param	int pPosY			, posição y que o helper aparecerá
-- @param	int pMirroring		, espelhamento do helper
-- @param	int pHelperIndex	, número deo helper chamado, se não for passado, assume-se o primeiro helper
function callHelper(pPosX,pPosY,pMirroring,pHelperIndex)
	lua_callHelper(objectPointer,pPosX,pPosY,pMirroring,pHelperIndex)
end

