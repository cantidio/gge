dofile("data/background/class_background.lua")
function script_object_getSpritePack()
	return this.spritePack
end

function script_object_getAnimationPack()
	return this.animationPack
end

function script_object_getName()
	return this.name;
end

function script_object_getId()
	return this.id
end

function script_object_setPointer(pPointer)
	this.mPointer = pPointer
end

function script_object_logic()
	this.logic()
end

---------------------------------------------------------------------------------------------------------------------------------------------------------
Mirroring = {
	Normal	= 0,
	HFlip	= 1,
	VFlip	= 2,
	VHflip	= 3,
	HVFlip	= 3
}
---------------------------------------------------------------------------------------------------------------------------------------------------------
--[[
	-- Classe que representa um objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	17/12/2009
	-- @version	02/01/2010
-]]
function Object(pPointer)
	local this = { }
	this.mPointer = pPointer
	--[[
		-- Método para retornar o nome do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	17/12/2009
		-- @return	string
	-]]
	local function getName()
		return lua_object_getName(this.mPointer)
	end

	--[[
		-- Método para retornar o id do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	17/12/2009
		-- @return	string
	-]]
	local function getId()
		return lua_object_getId(this.mPointer)
	end
	--[[
		-- Método para retornar o espelhamento do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	17/12/2009
		-- @return	int
	-]]
	local function getMirroring()
		return lua_object_getMirroring(this.mPointer)
	end
	--[[
		-- Método para setar o espelhamento do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	02/01/2010
		-- @param	Mirroring pMirroring, espelhamento a ser setado ao objeto
	-]]
	local function setMirroring(pMirroring)
		lua_object_setMirroring(this.mPointer,pMirroring)
	end
	--[[
		-- Método para retornar a posicão do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	17/12/2009
		-- @return	{x,y}
	-]]
	local function getPosition()
		local X,Y = lua_object_getPosition(this.mPointer)
		return {x = X, y = Y}
	end
	--[[
		-- Método para setar a posicão do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	17/12/2009
		-- @param	{x,y} pPosition, posicão a ser setada ao objeto
		-- @example
					obj = Object()
					pos	= { x = 1, y = 2 }
					obj.setPosition(pos)
	-]]
	local function setPosition(pPosition)
		lua_object_setPosition(
			this.mPointer,
			pPosition.x,
			pPosition.y
		)
	end
	--[[
		-- Método para adicionar uma posicão do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	17/12/2009
		-- @param	{x,y} pPosition, posicão a ser adicionada ao objeto
	-]]
	local function addPosition(pPosition)
		lua_object_addPosition(
			this.mPointer,
			pPosition.x,
			pPosition.y
		)
	end
	--[[
		-- Método para subtrair uma posicão do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	17/12/2009
		-- @param	{x,y} pPosition, posicão a ser subtraída ao objeto
	-]]
	local function subPosition(pPosition)
		lua_object_subPosition(
			this.mPointer,
			pPosition.x,
			pPosition.y
		)
	end
	--[[
		-- Método para mudar a animacão do objeto pelo seu índice
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	17/12/2009
		-- @param	int pIndex, índice real da animacão
	-]]
	local function changeAnimationByIndex(pIndex)
		lua_object_changeAnimation(this.mPointer,pIndex - 1)
	end
	--[[
		-- Método para mudar a animacão do objeto pelo seu grupo e índice
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	17/12/2009
		-- @param	int pGroup, grupo da animacão
		-- @param	int pIndex, índice da animacão
	-]]
	local function changeAnimation(pGroup,pIndex)
		lua_object_changeAnimation(
			this.mPointer,
			pGroup,
			pIndex
		)
	end
	--[[
		-- Método para retornar o layer do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	17/12/2009
		-- @return	Layer
	-]]
	local function getLayer()
		local layer = Layer(lua_object_getLayer(this.mPointer))
		return layer
	end

	local function logic()
		--logic of the object
	end
	
	this.getName				= getName
	this.getId					= getId
	this.getMirroring			= getMirroring
	this.setMirroring			= setMirroring

	this.getLayer				= getLayer

	this.getPosition			= getPosition
	this.setPosition			= setPosition

	this.addPosition			= addPosition
	this.subPosition			= subPosition
	
	this.getAnimationRealIndex	= getAnimationRealIndex
	this.changeAnimation		= changeAnimation
	this.isAnimationPlaying 	= isAnimationPlaying
	this.getAnimationPlaying	= getAnimationPlaying
	this.getFrameOn 			= getFrameOn
	this.setFrameOn 			= setFrameOn
	this.logic					= logic

--[[	setAfterImageMethodNormal
	setAfterImageMethodAdd
	setAfterImageMethodTrans
	setAfterImageEnabled
	setAfterImageDelay
	setAfterImageNumber
	setAfterImageMode
	getAfterImageEnabled
	getAfterImageDelay
	getAfterImageNumber
-]]
	return this
end


