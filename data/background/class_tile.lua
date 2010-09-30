--[[
	-- Classe que representa um tile de um layer
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	29/09/2010
	-- @param	string	pSpritePack		, pacote de sprites
	-- @param	string	pAnimationPack	, pacote de animaćões
	-- @param	int		pAnimation		, animaćão do tile
	-- @param	{x,y}	pPosition		, posićão do tile
	-- @param	Layer	pLayer			, layer em que o tile se encontra
-]]
function Tile(
	pSpritePack,
	pAnimationPack,
	pAnimation,
	pPosition,
	pLayer
)
	local this			= {}
	this.mSpritePack	= pSpritePack
	this.mAnimationPack	= pAnimationPack
	this.mPosition		= pPosition
	this.mAnimation		= pAnimation
	this.mLayer			= pLayer
	this.mPointer		= GGE_tile_new(
		pSpritePack,
		pAnimationPack,
		pAnimation,
		pPosition
	)
	--[[
		-- Método para deletar o tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	29/09/2010
	-]]
	this.delete = function()
		GGE_tile_delete(this.mPointer)
	end
	--[[
		-- Função que retorna a animação do tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	29/09/2010
		-- @return	int
	-]]
	this.getAnimation = function()
		return this.mAnimation
	end
	--[[
		-- Funcão que muda a animacao do tile
		-- 
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	29/09/2010
		-- @param	int pAnimation, numero da nova animacao
	-]]
	this.setAnimation = function(pAnimation)
		this.mAnimation = pAnimation
		GGE_tile_animationSet(this.mPointer,pAnimation);
	end

	--[[
		-- Funcão que clona o tile
		-- 
		-- @author	Cantidio Oliveira Fontes
		-- @since	14/12/2009
		-- @version	29/09/2010
		-- @param	{x,y} pPosition, posicão do tile clonado
	-]]
	this.clone = function(pPosition)
		return Tile(
			this.mSpritePack,
			this.mAnimationPack,
			this.mAnimation,
			pPosition
		)
	end

	--[[
		-- Funcão que retorna a posicão do tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	29/09/2010
		-- @return	{x,y}
	-]]
	this.getPosition = function()
		return this.mPosition
	end
	--[[
		-- Funcao para setar a posicao do tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	29/09/2010
		-- @param	{x,y} pPosition	, nova posicao para o tile
	-]]
	this.setPosition = function(pPosition)
		this.mPosition = pPosition
	end

	--[[
		-- Método para desenhar o tile diretamente
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	29/09/2010
		-- @param	{x,y} pPosition, posićão a desenhar o tile
	-]]
	this.directDraw = function(pPosition)
		GGE_tile_draw(
			this.mPointer,
			pPosition.x,
			pPosition.y
		)
	end
	
	--[[
		-- Funcao para retornar o layer do tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	29/09/2010
		-- @return	Layer
	-]]
	this.getLayer = function()
		return this.mLayer
	end

	return this
end

