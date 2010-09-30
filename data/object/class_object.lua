dofile("data/background/class_background.lua")
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
function OLD_Object(pPointer)
	local this = { }
	
	this.mPointer = pPointer	
	
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

	return this
end
-------------------------------------------------------------------------------------------------_NEW_
--[[
	-- Classe que representa um objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	17/12/2009
	-- @version	29/09/2010
-]]
function Object(pSprite, pAnimation)
	local this = { }

	this.mDirection	= Mirroring.normal
	this.mPosition	= { x = 0, y = 0 }
	this.mId		= 0
	this.mLayer		= { } --layer que o objeto se encontra
	this.mActive	= true
	--this.mSprite	= "" 
	--this.mAnimation	= ""

	this.mPointer	= GGE_object_new(pSprite,pAnimation)
	--[[
		-- Método destrutor
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
	-]]
	this.delete = function()
		GGE_object_delete(this.mPointer)
		this = {}
	end
	--[[
		-- Método para ativar o objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	29/09/2010
	-]]
	this.activate = function()
		this.mActive = true
	end
	
	--[[
		-- Método para desativar o objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	29/09/2010
	-]]
	this.inactivate = function()
		this.mActive = false
	end
	
	--[[
		-- Método para retornar se o objeto está ativo
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	29/09/2010
		-- @return	bool
	-]]
	this.isActive = function()
		return this.mActive
	end
----------------------------------------------------------------------------------------------------------------------------------------------------	
--	this.getMirroring				= getMirroring
--	this.setMirroring				= setMirroring
----------------------------------------------------------------------------------------------------------------------------------------------------	
	--[[
		-- Método para setar o id do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	29/09/2010
		-- @param	string pId, o id do objeto
	-]]
	this.setId = function(pId)
		this.mId = pId
	end
	
	--[[
		-- Método para retornar o id do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	29/09/2010
		-- @return	string
	-]]
	this.getId = function()
		return this.mId
	end

	--[[
		-- Método para retornar o layer do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	29/09/2010
		-- @return	Layer
		-- @todo rever isso
	-]]
	this.getLayer = function()
		--local layer = Layer( GGE_object_getLayer(this.mPointer) )
		return this.mLayer
	end

	--[[
		-- Método para retornar a posicão do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	29/09/2010
		-- @return	{x,y}
	-]]
	this.getPosition = function()
		return this.mPosition
	end

	--[[
		-- Método para setar a posicão do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	29/09/2010
		-- @param	{x,y} pPosition, posicão a ser setada ao objeto
		-- @example
					obj = Object()
					pos	= { x = 1, y = 2 }
					obj.setPosition(pos)
	-]]
	this.setPosition = function(pPosition)
		this.mPosition = pPosition
	end

	--[[
		-- Método para adicionar uma posicão ao objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	29/09/2010
		-- @param	{x,y} pPosition, posicão a ser adicionada ao objeto
	-]]
	this.addPosition = function(pPosition)
		this.mPosition.x += pPosition.x
		this.mPosition.y += pPosition.y
	end

	--[[
		-- Método para subtrair uma posicão do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	29/09/2010
		-- @param	{x,y} pPosition, posicão a ser subtraída ao objeto
	-]]
	this.subPosition = function(pPosition)
		this.mPosition.x -= pPosition.x
		this.mPosition.y -= pPosition.y
	end
	
	--[[
		-- Método para mudar a animacão do objeto pelo seu índice
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	29/09/2010
		-- @param	int pIndex, índice real da animacão
	-]]
	this.changeAnimationByIndex = function(pIndex)
		GGE_object_animationChangeByIndex(this.mPointer, pIndex - 1)
	end
	--[[
		-- Método para mudar a animacão do objeto pelo seu grupo e índice
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/12/2009
		-- @version	29/09/2010
		-- @param	int pGroup, grupo da animacão
		-- @param	int pIndex, índice da animacão
	-]]
	this.changeAnimation = function(pGroup, pIndex)
		GGE_object_animationChange(
			this.mPointer,
			pGroup,
			pIndex
		)
	end
	--[[
		-- Método para retornar a grupo e o índice do grupo da animacão que o objeto está executando
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	29/09/2010
		-- @return	{group, index, realIndex}
	-]]
	local function getAnimationOn()
		local Group, Index, Real = GGE_object_animationOnGet(this.mPointer)
		return  { group = Group, index = Index, realIndex = Real }
	end
	--[[
		-- Método para retornar se alguma animaćão está tocando
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	29/09/2010
		-- @return	bool
	-]]
	this.animationIsPlaying = function()
		return GGE_object_animationIsPlaying(this.mPointer)
	end
	--[[
		-- Método para retornar o índice real da animaćão
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	29/09/2010
		-- @return	{group,index}
	-]]
	this.getAnimationRealIndex = function(pGroup,pIndex)
		return GGE_object_animationGetRealIndex(
			this.mPointer,
			pGroup,
			pIndex
		) + 1
	end
	--[[
		-- Método para recuperar o frame da animacão atual
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	29/09/2010
		-- @return	int
	-]]
	this.getFrameOn = function()
		return GGE_object_animationGetFrameOn(this.mPointer)
	end
	--[[
		-- Método para setar o frame da animacão atual
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	29/09/2010
		-- @param	int pFrame, indice do frame a setar
	-]]
	this.setFrameOn = function(pFrame)
		GGE_object_animationSetFrameOn(this.mPointer, pFrame)
	end
	
	--[[
		-- Método para desenhar normalmente
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	29/09/2010
	-]]
	this.draw = function(pPosition)
		GGE_object_draw(
			this.mPointer,
			this.mPosition.x + pPosition.x,
			this.mPosition.y + pPosition.y,
			this.mDirection
		)
	end
	--[[
		-- Método para desenhar
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	29/09/2010
		-- @param	{x,y} pPosition, posicão a desenhar o objeto
		-- @param	Mirroring pDirection, direcao do personagem
	-]]
	this.directDraw = function(pPosition, pDirection)
		if this.isActive() then
			GGE_objectDraw(
				this.mPointer,
				pPosition.x,
				pPosition.y,
				pDirection
			)
		end
	end

	--[[
		-- Método para executar a lógica do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	29/09/2010
		-- @details
		--	Esse método deve ser impletado pela classe que derivar
	-]]
	this.logic = function()
		GGE_object_animationRunStep(this.mPointer)
		--logica do objeto
	end

	print("classe Object criada, ponteiro de acesso em c++: " .. this.mPointer)
	return this
end
