dofile("data/background/class_background.lua")
--[[
	-- Funcão para retornar a localizacão do pacote de sprites do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	02/01/2009
	-- @version	04/01/2009
	-- @return	string
-]]
function script_object_getSpritePack()
	return this.spritePack
end
--[[
	-- Funcão para retornar a localizacão do pacote de animacões do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	02/01/2009
	-- @version	04/01/2009
	-- @return	string
-]]
function script_object_getAnimationPack()
	return this.animationPack
end
--[[
	-- Funcão para retornar o nome do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	02/01/2009
	-- @version	04/01/2009
	-- @return	string
-]]
function script_object_getName()
	return this.name
end
--[[
	-- Funcão para retornar o id do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	02/01/2009
	-- @version	04/01/2009
	-- @return	string
-]]
function script_object_getId()
	return this.id
end
--[[
	-- Funcão para setar o ponteiro da classe em c++ para o objeto em Lua
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	02/01/2009
	-- @version	04/01/2009
-]]
function script_object_setPointer(pPointer)
	this.mPointer = pPointer
end
--[[
	-- Funcão para rodar a lógica dos scripts
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	02/01/2009
	-- @version	04/01/2009
-]]
function script_object_logic()
	this.logic()
end
--[[
	-- Funcão para rodar a funcão persistent do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	25/01/2010
	-- @version	25/01/2010
-]]
function script_object_persistentFunction()
	this.persistentFunction()
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
	-- @version	04/01/2010
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
		-- Método para retornar se o objeto está ativo
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	local function isActive()
		return lua_object_isActive(this.mPointer)
	end
	--[[
		-- Método para ativar o objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
	-]]
	local function activate()
		lua_object_activate(this.mPointer)
	end
	--[[
		-- Método para desativar o objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
	-]]
	local function inactivate()
		lua_object_inactivate(this.mPointer)
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
	--[[
		-- Função que seta o método das AfterImages para Normal
		--
		-- @author      Cantidio Oliveira Fontes
		-- @since       26/06/2009
		-- @version     02/01/2010
	-]]
	local function setAfterImageMethodNormal()
        lua_object_setAfterImageMethodNormal(this.mPointer)
	end
	--[[
		-- Função que sera o método das AfterImages para add
		--
		-- @author      Cantidio Oliveira Fontes
		-- @since       26/06/2009
		-- @version     02/01/2010
		-- @param       {red,blue,green}	pColorAdd	, componente vermelho a ser adicionado
		-- @param       {red,blue,green}	pColorSub	, componente vermelho a ser subtraído
		-- @param       float   			pTrans		, valor da transparencia
	-]]
	local function setAfterImageMethodAdd(
		pColorAdd,
		pColorSub,
		pTrans
	)
		lua_object_setAfterImageMethodAdd(
			this.mPointer,
			pColorAdd.red,
			pColorAdd.green,
			pColorAdd.blue,
			pColorSub.red,
			pColorSub.green,
			pColorSub.blue,
			pTrans
		)
	end

	--[[
		-- Função que sera o método das AfterImages para Trans
		--
		-- @author      Cantidio Oliveira Fontes
		-- @since       26/06/2009
		-- @version     02/01/2010
		-- @param       float   pTrans, valor da transparencia
	-]]
	local function setAfterImageMethodTrans(pTrans)
		lua_object_setAfterImageMethodTrans(this.mPointer,pTrans)
	end

	--[[
		-- Método para retornar se o modo de after images está habilitado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/06/2009
		-- @version	04/01/2010
		-- @param	bool pEnabled, se o modo de after images está habilitado ou não
	-]]
	local function setAfterImageEnabled(pEnabled)
		lua_object_setAfterImageEnabled(this.mPointer,pEnabled)
	end
	
	--[[
		-- Método para retornar se o modo de after images está habilitado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/06/2009
		-- @version	04/01/2010
		-- @param	int pDelay, delay entre cada after image
	-]]
	local function setAfterImageDelay(pDelay)
		lua_object_setAfterImageDelay(this.mPointer,pDelay)
	end
	
	--[[
		-- Método para retornar se o modo de after images está habilitado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/06/2009
		-- @version	04/01/2010
		-- @return	int pNumber, número de afterImages máximo permitido
	-]]
	local function setAfterImageNumber(pNumber)
		lua_object_setAfterImageNumber(this.mPointer,pNumber)
	end

	--[[
		-- Método para setar o método de afterImages
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/06/2009
		-- @version	04/01/2010
		-- @param	bool	pEnabled		, se o modo de after images está habilitado ou não
		-- @param	int		pDelay			, delay entra cada after image
		-- @param	int		pImageNumber	, número máximo de after images	
	-]]
	local function setAfterImageMode(
		pEnabled,
		pDelay,
		pImageNumber
	)
		lua_object_setAfterImageMode(
			this.mPointer,
			pEnabled,
			pDelay,
			pImageNumber
		)
	end

	local function logic()
		--logic of the object
	end
	
	local function persistentFunction()
		--
	end
	
	this.getName					= getName
	this.getId						= getId
	this.ativate					= ativate
	this.inativate					= inativate
	this.isAtive					= isAtive
	this.getMirroring				= getMirroring
	this.setMirroring				= setMirroring
	this.getLayer					= getLayer
	this.getPosition				= getPosition
	this.setPosition				= setPosition
	this.addPosition				= addPosition
	this.subPosition				= subPosition
	this.getAnimationRealIndex		= getAnimationRealIndex
	this.changeAnimation			= changeAnimation
	this.isAnimationPlaying 		= isAnimationPlaying
	this.getAnimationPlaying		= getAnimationPlaying
	this.getFrameOn 				= getFrameOn
	this.setFrameOn 				= setFrameOn
	this.logic						= logic
	this.persistentFunction			= persistentFunction
	this.setAfterImageMethodNormal	= setAfterImageMethodNormal
	this.setAfterImageMethodAdd		= setAfterImageMethodAdd
	this.setAfterImageMethodTrans	= setAfterImageMethodTrans
	this.setAfterImageEnabled		= setAfterImageEnabled
	this.setAfterImageDelay			= setAfterImageDelay
	this.setAfterImageNumber		= setAfterImageNumber
	this.setAfterImageMode			= setAfterImageMode

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


