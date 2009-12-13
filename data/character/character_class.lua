dofile("data/object/object_class.lua")

--[[
	-- Classe que representa um Character em LUA
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/03/2009
	-- @version	09/08/2009
-]]
function Character(pPointer)
	local obj = { }
	obj = Object(pPointer)

	--[[
		-- Função que retorna o número de helpers que o personagem possui
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/03/2009
		-- @final	13/03/2009
		-- @return	int
	-]]
	local function getHelpersNumber()
		return #helperScriptFile;
	end

	--[[
		-- Função que retorna o número máximo de instâncias de um determinado helper
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/03/2009
		-- @final	13/03/2009
		-- @param	int pIndex, índice do helper a verificar quantas instâncias
		-- @return	int
	-]]
	local function getHelperMaxInstances(pIndex)
		return helperMaxInstances[pIndex]
	end

	--[[
		-- Função que retorna o arquivo de script de um determinado helper
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/03/2009
		-- @final	13/03/2009
		-- @param	int pIndex, índice do helper a verificar o arquivo de script
		-- @return	string
	-]]
	local function getHelperScriptFile(pIndex)
		return helperScriptFile[pIndex]
	end

	--[[
		-- Função para retornar o life do personagem
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	12/03/2009
		-- @final	12/03/2009
		-- @return	int
	-]]
	local function getLife()
		return lua_getLife(obj.pointer)
	end

	--[[
		-- Função para setar o life do personagem
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	12/03/2009
		-- @final	12/03/2009
		-- @param	int pLife, life do personagem
	-]]
	local function setLife(pLife)
		return lua_setLife(obj.pointer,pLife)
	end

	--[[
		-- Função para retirar um valor do life do personagem
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	12/03/2009
		-- @final	12/03/2009
		-- @param	int pLife, life a ser subtraído
	-]]
	local function subLife(pLife)
		return lua_subLife(obj.pointer,pLife)
	end

	--[[
		-- Função para adicionar um valor ao life do personagem
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	12/03/2009
		-- @final	12/03/2009
		-- @param	int pLife, life a ser adicionado
	-]]
	local function addLife(pLife)
		return lua_addLife(obj.pointer,pLife)
	end

	--[[
		-- Função que retorna verdadeiro se o personagem está vivo
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	12/03/2009
		-- @final	12/03/2009
		-- @return	bool
	-]]
	local function isAlive()
		return lua_isAlive(obj.pointer)
	end

	--[[
		-- Função que ativa o personagem
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	12/03/2009
		-- @final	12/03/2009
	-]]
	local function ativate()
		lua_ativate(obj.pointer)
	end

	--[[
		-- Função que ativa o personagem
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	12/03/2009
		-- @final	12/03/2009
	-]]
	local function inativate()
		lua_inativate(obj.pointer)
	end

	--[[
		-- Função que retorna verdadeiro se o personagem está ativo
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	12/03/2009
		-- @final	12/03/2009
		-- @return	bool
	-]]
	local function isAtive()
		return lua_isAtive(obj.pointer)
	end

	--[[
		-- Função que retorna verdadeiro se o personagem está imortal
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	12/03/2009
		-- @final	12/03/2009
		-- @return	bool
	-]]
	local function isImortal()
		return lua_isImortal(obj.pointer)
	end

	--[[
		-- Função que machuca o personagem
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	12/03/2009
		-- @final	12/03/2009
		-- @param	int pDamage, valor de dano recebido
	-]]
	local function hurt(pDamage)
		return lua_hurt(obj.pointer,pDamage)
	end

	--[[
		-- Função que chama um helper do personagem
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	12/03/2009
		-- @final	12/03/2009
		-- @param	int pPosX			, posição x que o helper aparecerá
		-- @param	int pPosY			, posição y que o helper aparecerá
		-- @param	int pMirroring		, espelhamento do helper
		-- @param	int pHelperIndex	, número deo helper chamado, se não for passado, assume-se o primeiro helper
		-- @return	int	, Endereço para o helper chamado
	-]]
	local function callHelper(pPosX,pPosY,pMirroring,pHelperIndex)
		helperPointer = lua_callHelper(
			obj.pointer,
			pPosX,
			pPosY,
			pMirroring,
			pHelperIndex
		)
		setLastHelperCalledPointer(helperPointer)
		return helperPointer
	end
	
	obj.getHelpersNumber		= getHelpersNumber
	obj.getHelperMaxInstances	= getHelperMaxInstances
	obj.getHelperScriptFile		= getHelperScriptFile
	obj.getLife					= getLife
	obj.setLife					= setLife
	obj.subLife					= subLife
	obj.addLife					= addLife
	obj.isAlive					= isAlive
	obj.ativate					= ativate
	obj.inativate				= inativate
	obj.isAtive					= isAtive
	obj.isImortal				= isImortal
	obj.hurt					= hurt
	obj.callHelper				= callHelper

	return obj
end

