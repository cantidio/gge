print("include: GGE_Object")
Mirroring = {
	Normal	= 0,
	HFlip	= 1,
	VFlip	= 2,
	VHflip	= 3,
	HVFlip	= 3
}
--[[
	-- Constructor
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	20/10/2010
	-- @param	string		pSpritePack		, location of the SpritePack
	-- @param	string		pAnimationPack	, location of the AnimationPack
	-- @param	GGE_Layer	pLayer			, the layer of the object
	-- @param	{x,y}		pPosition		, position of the Object
	-- @return	GGE_Object
-]]
GGE_Object = class(
	function(
		self,
		pSpritePack,
		pAnimationPack,
		pLayer,
		pPosition
	)
		GGE_game_log("GGE_Object.new()")

		self.mObject = GGE_OBJECT_BASIC:new(
			pSpritePack,
			pAnimationPack
		)
		self.mSpritePack	= pSpritePack		or ""
		self.mAnimationPack	= pAnimationPack	or ""
		self.mPosition		= pPosition			or {x=0, y=0}
		self.mActive		= true
		self.mId			= ""
		self.mLayer			= pLayer

		GGE_game_log("GGE_Object.~new()")
	end
)
--[[
	-- Método para ativar o objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	18/10/2010
-]]
function GGE_Object:activate()
	self.mActive = true
end
--[[
	-- Método para desativar o objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	18/10/2010
-]]
function GGE_Object:deactivate()
	self.mActive = false
end
--[[
	-- Método para retornar se o objeto está ativo
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	18/10/2010
	-- @return	bool
-]]
function GGE_Object:isActive()
	return self.mActive
end
--[[
	-- Método para retornar o espelhamento do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	01/10/2010
	-- @version	18/10/2010
	-- @return	Mirroring
-]]
function GGE_Object:getMirroring()
	return self.mMirroring
end
--[[
	-- Método para retornar o espelhamento do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	01/10/2010
	-- @version	18/10/2010
	-- @param	Mirroring pMirroring, espelhamento do objeto
-]]
function GGE_Object:setMirroring(pMirroring)
	self.mMirroring = pMirroring
end
--[[
	-- Método para setar o id do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	29/09/2010
	-- @version	18/10/2010
	-- @param	string pId, o id do objeto
-]]
function GGE_Object:setId(pId)
	self.mId = pId
end
--[[
	-- Método para retornar o id do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	17/12/2009
	-- @version	18/10/2010
	-- @return	string
-]]
function GGE_Object:getId()
	return self.mId
end
--[[
	-- Método para setar o layer do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	01/10/2010
	-- @version	18/10/2010
	-- @param	GGE_Layer pLayer, layer do objeto
-]]
function GGE_Object:setLayer(pLayer)
	self.mLayer = pLayer
end
--[[
	-- Método para retornar o layer do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	17/12/2009
	-- @version	18/10/2010
	-- @return	Layer
-]]
function GGE_Object:getLayer()
	return self.mLayer
end
--[[
	-- Método para retornar a posicão do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	17/12/2009
	-- @version	18/10/2010
	-- @return	{x,y}
-]]
function GGE_Object:getPosition()
	return self.mPosition
end
--[[
	-- Método para setar a posicão do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	17/12/2009
	-- @version	18/10/2010
	-- @param	{x,y} pPosition, posicão a ser setada ao objeto
	-- @example
				obj = Object()
				pos	= { x = 1, y = 2 }
				obj.setPosition(pos)
-]]
function GGE_Object:setPosition(pPosition)
	self.mPosition = pPosition
end
--[[
	-- Método para adicionar uma posicão ao objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	17/12/2009
	-- @version	18/10/2010
	-- @param	{x,y} pPosition, posicão a ser adicionada ao objeto
-]]
function GGE_Object:addPosition(pPosition)
	self.mPosition.x = self.mPosition.x + pPosition.x
	self.mPosition.y = self.mPosition.y + pPosition.y
end
--[[
	-- Método para subtrair uma posicão do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	17/12/2009
	-- @version	18/10/2010
	-- @param	{x,y} pPosition, posicão a ser subtraída ao objeto
-]]
function GGE_Object:subPosition(pPosition)
	self.mPosition.x = self.mPosition.x - pPosition.x
	self.mPosition.y = self.mPosition.y - pPosition.y
end
--[[
	-- Método para mudar a animacão do objeto pelo seu índice
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	17/12/2009
	-- @version	18/10/2010
	-- @param	int pIndex, índice real da animacão, 1 - N
-]]
function GGE_Object:changeAnimationByIndex(pIndex)
	self.mObject:changeAnimationByIndex(pIndex - 1)
end
--[[
	-- Método para mudar a animacão do objeto pelo seu grupo e índice
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	17/12/2009
	-- @version	18/10/2010
	-- @param	int pGroup, grupo da animacão
	-- @param	int pIndex, índice da animacão
-]]
function GGE_Object:changeAnimation(pGroup, pIndex)
	self.mObject:changeAnimation(
		pGroup,
		pIndex
	)
end
--[[
	-- Método para retornar a grupo e o índice do grupo da animacão que o objeto está executando
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	18/10/2010
	-- @return	{group, index, realIndex}
-]]
function GGE_Object:getAnimationOn()
	local Real Group, Index = self.mObject:getAnimationOn()
	return  { group = Group, index = Index, realIndex = Real }
end
--[[
	-- Método para retornar se alguma animacão está tocando
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	18/10/2010
	-- @return	bool
-]]
function GGE_Object:animationIsPlaying()
	return self.mObject:animationIsPlaying()
end
--[[
	-- Método para retornar o índice real da animacão
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	18/10/2010
	-- @return	{group,index}
-]]
function GGE_Object:getAnimationRealIndex(pGroup,pIndex)
	return self.mObject:getAnimationRealIndex(
		pGroup,
		pIndex
	) + 1
end
--[[
	-- Método para recuperar o frame da animacão atual
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	29/09/2010
	-- @version	18/10/2010
	-- @return	int
-]]
function GGE_Object:getFrameOn()
	return self.mObject:getFrameOn()
end
--[[
	-- Método para setar o frame da animacão atual
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	29/09/2010
	-- @version	18/10/2010
	-- @param	int pFrame, indice do frame a setar
-]]
function GGE_Object:setFrameOn(pFrame)
	self.mObject:setFrameOn(pFrame)
end
--[[
	-- Método para desenhar normalmente
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	29/09/2010
	-- @version	20/10/2010
-]]
function GGE_Object:draw(pPosition)
	self.mObject:draw(
		self.mPosition.x + pPosition.x,
		self.mPosition.y + pPosition.y,
		self.mMirroring
	)
end
--[[
	-- Método para desenhar
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	29/09/2010
	-- @version	20/10/2010
	-- @param	{x,y} pPosition, posicão a desenhar o objeto
	-- @param	Mirroring pDirection, direcao do personagem
-]]
function GGE_Object:directDraw(pPosition, pDirection)
	self.mObject:draw(
		pPosition.x,
		pPosition.y,
		pDirection
	)
end
--[[
	-- Método para executar a lógica do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	29/09/2010
	-- @version	18/10/2010
	-- @details
-]]
function GGE_Object:basicLogic()
		self.mObject:logic()--animationRunStep()
end
--[[
	-- Método para executar a lógica do objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	29/09/2010
	-- @version	18/10/2010
	-- @details Esse Método deve ser impletado pela classe que derivar
-]]
function GGE_Object:logic()
	self:basicLogic()
end

