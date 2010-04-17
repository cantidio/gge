dofile("data/object/class_object.lua")

function script_character_getLife()
	return this.life
end

function script_character_getImortalTime()
	return this.imortalTime
end

function script_character_getHelpersNumber()
	return this.getHelpersNumber()
end

function script_character_getHelperMaxInstances(pIndex)
	this.getHelperMaxInstances(pIndex)
end

function script_character_getHelperScriptFile(pIndex)
	this.getHelperScriptFile(pIndex)
end

function script_character_setParentPointer(pParentPointer)
	this.setParentPointer(pParentPointer)
end
-------------------------------------------------------------------------------------------------------------------------------------------------------
--[[
	-- Classe que representa um Character em LUA
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/03/2009
	-- @version	09/08/2009
-]]
function Character(pPointer,pParent)
	local this = { }
	this			= Object(pPointer)
	this.mParent	= pParent

	--[[
		-- Função que retorna o número de helpers que o personagem possui
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/03/2009
		-- @final	13/03/2009
		-- @return	int
	-]]
	local function getHelpersNumber()
		return #this.helperScriptFile;
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
		return this.helperMaxInstances[pIndex]
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
		return this.helperScriptFile[pIndex]
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
		return lua_character_getLife(this.mPointer)
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
		return lua_character_setLife(this.mPointer,pLife)
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
		return lua_character_subLife(this.mPointer,pLife)
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
		return lua_character_addLife(this.mPointer,pLife)
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
		return lua_character_isAlive(this.mPointer)
	end

	--[[
		-- Função que chama um helper do personagem
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	12/03/2009
		-- @final	12/03/2009
		-- @param	{x,y}	pPosition		, posição que o helper aparecerá
		-- @param	int		pMirroring		, espelhamento do helper
		-- @param	int		pHelperIndex	, número deo helper chamado, se não for passado, assume-se o primeiro helper
		-- @return	int		, Endereço para o helper chamado
	-]]
	local function callHelper(pPosition,pMirroring,pHelperIndex)
		helperPointer = lua_character_callHelper(
			this.mPointer,
			pPosition.x,
			pPosition.y,
			pMirroring,
			pHelperIndex
		)
		setLastHelperCalledPointer(helperPointer)
		return Character(helperPointer,this.mPointer)
	end
	
	local function setParentPointer(pParent)
		this.mParent = pParent
	end
	
	local function getParent()
		return Character(this.mParent,nil)
	end
	
	this.getHelpersNumber		= getHelpersNumber
	this.getHelperMaxInstances	= getHelperMaxInstances
	this.getHelperScriptFile	= getHelperScriptFile
	this.getLife				= getLife
	this.setLife				= setLife
	this.subLife				= subLife
	this.addLife				= addLife
	this.isImortal				= isImortal
	this.callHelper				= callHelper
	
	return this
end

