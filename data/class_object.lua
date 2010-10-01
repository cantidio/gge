print("include: GGE_Object")
Mirroring = {
	Normal	= 0,
	HFlip	= 1,
	VFlip	= 2,
	VHflip	= 3,
	HVFlip	= 3
}
--[[
	-- Classe que representa um objeto
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	17/12/2009
	-- @version	30/09/2010
	-- @param	string		pSprite		, nome do pacote de sprites do objeto
	-- @param	string		pAnimation	, nome do pacote de animacoes do objeto
	-- @param	GGE_Layer	pLayer		, layer o qual o objeto se encontra
-]]
function GGE_Object(pSprite, pAnimation, pLayer)
	GGE_game_log("GGE_Object()")
	local this = { }

	this.mMirroring	= Mirroring.normal	--espelhamento do objeto
	this.mPosition	= { x = 0, y = 0 }	--posicão do objeto
	this.mId		= ""				--
	this.mLayer		= pLayer --layer que o objeto se encontra
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
	--[[
		-- Método para retornar o espelhamento do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	01/10/2010
		-- @version	01/10/2010
		-- @return	Mirroring
	-]]
	this.getMirroring = function()
		return this.mMirroring
	end
	--[[
		-- Método para retornar o espelhamento do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	01/10/2010
		-- @version	01/10/2010
		-- @param	Mirroring pMirroring, espelhamento do objeto
	-]]
	this.setMirroring = function(pMirroring)
		this.mMirroring = pMirroring
	end
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
		-- Método para setar o layer do objeto
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	01/10/2010
		-- @version	01/10/2010
		-- @param	GGE_Layer pLayer, layer do objeto
	-]]
	this.setLayer = function(pLayer)
		this.mLayer = pLayer
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
		this.mPosition.x = this.mPosition.x + pPosition.x
		this.mPosition.y = this.mPosition.y + pPosition.y
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
		this.mPosition.x = this.mPosition.x - pPosition.x
		this.mPosition.y = this.mPosition.y - pPosition.y
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
		-- Método para retornar se alguma animacão está tocando
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
		-- Método para retornar o índice real da animacão
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
			this.mMirroring
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
			GGE_object_draw(
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
		--	Esse Método deve ser impletado pela classe que derivar
	-]]
	this.basicLogic = function()
		GGE_object_animationRunStep(this.mPointer)
		--logica do objeto
	end

	return this
end

