print("include: GGE_Tile")
GGE_Tile = class()
--[[
	-- Metodo Construtor da Classe que representa um tile de um layer
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	21/10/2010
	-- @param	string	pSpritePack		, pacote de sprites
	-- @param	string	pAnimationPack	, pacote de animaćões
	-- @param	int		pAnimation		, animaćão do tile
	-- @param	{x,y}	pPosition		, posićão do tile
	-- @param	GGE_Layer	pLayer		, layer em que o tile se encontra
	-- @return	GGE_Tile
-]]
function GGE_Tile:new(
	pSpritePack,
	pAnimationPack,
	pAnimation,
	pPosition,
	pLayer
)
	local self = {}
	self.mTile = GGE_TILE_BASIC:new(
		pSpritePack,
		pAnimationPack,
		pAnimation,
		pPosition
	)
	self.mSpritePack	= pSpritePack
	self.mAnimationPack	= pAnimationPack
	self.mPosition		= pPosition
	self.mAnimation		= pAnimation
	self.mLayer			= pLayer
	
	--[[
		-- Função que retorna a animação do tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	18/10/2010
		-- @return	int
	-]]
	function self:getAnimation()
		return self.mTile:getAnimation()
	end
	--[[
		-- Funcão que muda a animacao do tile
		-- 
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	18/10/2010
		-- @param	int pAnimation, numero da nova animacao
	-]]
	function self:setAnimation(pAnimation)
		self.mTile:setAnimation(pAnimation)
	end
	--[[
		-- Funcão que retorna a posicão do tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	18/10/2010
		-- @return	{x,y}
	-]]
	function self:getPosition()
		return self.mPosition
	end
	--[[
		-- Funcao para setar a posicao do tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	18/10/2010
		-- @param	{x,y} pPosition	, nova posicao para o tile
	-]]
	function self:setPosition(pPosition)
		self.mPosition = pPosition
	end
	--[[
		-- Metodo que clona o tile
		-- 
		-- @author	Cantidio Oliveira Fontes
		-- @since	14/12/2009
		-- @version	18/10/2010
		-- @param	{x,y} pPosition, posicão do tile clonado
	-]]
	function self:clone(pPosition)
		return GGE_Tile.new(
			self.mSpritePack,
			self.mAnimationPack,
			self.mAnimation,
			pPosition
		)
	end
	--[[
		-- Funcao para adicionar um valor a posicao do tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	01/10/2010
		-- @version	18/10/2010
		-- @param	{x,y} pPosition	, posicao a ser adicionada a posicao do tile
	-]]
	function self:addPosition(pPosition)
		self.mPosition.x = self.mPosition.x + pPosition.x
		self.mPosition.y = self.mPosition.y + pPosition.y
	end
	--[[
		-- Funcao para subtrair um valor a posicao do tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	01/10/2010
		-- @version	18/10/2010
		-- @param	{x,y} pPosition	, posicao a ser subtraida da posicao do tile
	-]]
	function self:subPosition(pPosition)
		self.mPosition.x = self.mPosition.x - pPosition.x
		self.mPosition.y = self.mPosition.y - pPosition.y
	end
	--[[
		-- Method that draws the tile directly in the screen
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	18/10/2010
		-- @param	{x,y} pPosition, position to draw the tile
	-]]
	function self:directDraw(pPosition)
		self.mTile:draw(
			pPosition.x,
			pPosition.y
		)
	end
	--[[
		-- Method that draws the tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	18/10/2010
		-- @param	{x,y} pPosition, the position to draw the tile
	-]]
	function self:draw(pPosition)
		self.mTile:draw(
			self.mPosition.x + pPosition.x,
			self.mPosition.y + pPosition.y
		)
	end
	--[[
		-- Method that returns the GGE_Layer of the tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	18/10/2010
		-- @return	GGE_Layer
	-]]
	function self:getLayer()
		return self.mLayer
	end
	--[[
		-- Method that sets the layer of the Tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	17/10/2010
		-- @version	18/10/2010
		-- @param	GGE_Layer pLayer, the layer of the Tile
	-]]
	function self:setLayer(pLayer)
		self.mLayer = pLayer;
	end
	--[[
		-- Method that executes the logic of the Tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	01/10/2010
		-- @version	18/10/2010
		-- @param	GGE_Layer pLayer, the layer of the Tile
	-]]
	function self:logic()
		self.mTile:logic()
	end
	
	return self
end

