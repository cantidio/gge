print("include: GGE_Layer")
GGE_Layer = class()
--[[
	-- Classe que representa um layer de um Cenário
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	13/12/2009
	-- @version	30/09/2010
	-- @param	string pSpritePack			, localizacão do arquivo de sprites do layer
	-- @param	string pAnimationPack		, localizacão do arquivo de animacoes do layer
	-- @param	GGE_Background pBackground	, cenário ao qual o layer está inserido
-]]
function GGE_Layer:new(pSpritePack, pAnimationPack, pBackground)
	local self			= {}
	self.mBackground	= pBackground				--Referencia ao cenário do layer
	self.mTiles			= { }						--Vetor com os tiles do layer
	self.mObjects		= { }						--Vetor com os objetos do layer
	self.mSpritePack	= pSpritePack		or ""	--Localização do arquivo de sprites do layer
	self.mAnimationPack	= pAnimationPack	or ""	--Localização do arquivo de animações do layer
	self.mScrollSpeed	= {x = 1, y = 1}			--Velocidade de deslocamento do layer
	self.mId			= ""
	self.mActive		= true
	
	--[[
		-- Method to activate the layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	18/10/2010
	-]]
	function self:activate()
		self.mActive = true
	end
	--[[
		-- Method to deactivate the layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	18/10/2010
	-]]
	function self:deactivate()
		self.mActive = false
	end
	--[[
		-- Method that returns if the layer is active
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	18/10/2010
		-- @return	bool
	-]]
	function self:isActive()
		return self.mActive
	end
	--[[
		-- Método para setar o id do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
		-- @param	string pId, id do layer
	-]]
	function self:setId(pId)
		self.mId = pId
	end
	--[[
		-- Método para pegar o id do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
		-- @return	string, id do layer
	-]]
	function self:getId()
		return self.mId
	end
	--[[
		-- Método para adicionar um tile ao layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
		-- @param	Tile pTile, tile a ser adicionado
	-]]
	function self:addTile(pTile)
		pTile:setLayer(this)
		self.mTiles[#self.mTiles + 1] = pTile
	end
	--[[
		-- Método que retorna o número de tiles do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	29/09/2010
		-- @return	int
	-]]
	function self:getTileNumber()
		return #self.mTiles;
	end
	--[[
		-- Método que retorna um tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	29/09/2010
		-- @param	int pTile, indice do tile
		-- @return	Tile
	-]]
	function self:getTile(pTile)
		return self.mTiles[pTile]
	end
	--[[
		-- Funcao que remove um tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	29/09/2010
		-- @param	int pTile, indice do tile
	-]]
	function self:removeTile(pTile)
		if not self.mTiles[pTile] == nil then
			--self.mTiles[pTile].delete()
			self.mTiles[pTile] = nil
		end
	end
	--[[
		--Função que retorna o background do Layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	15/12/2009
		-- @version	29/09/2010
		-- @return	Background
	-]]
	function self:getBackground()
		return self.mBackground
	end
	--[[
		--Função que seta o background do Layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	15/12/2009
		-- @version	29/09/2010
		-- @param	Background pBackground, o nome cenário
	-]]
	function self:setBackground(pBackground)
		self.mBackground = pBackground
	end
	--[[
		-- Método para adicionar um objeto ao layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	01/10/2010
		-- @version	01/10/2010
		-- @param	GGE_Object pObject, objeto a ser adicionado ao layer
	-]]
	function self:addObject(pObject)
		pObject:setLayer(this)
		self.mObjects[#self.mObjects + 1] = pObject
	end
	--[[
		--Função que retorna o número de objects do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	29/09/2010
		-- @return	int
	-]]
	function self:getObjectNumber()
		return #self.mObjects
	end
	--[[
		-- Método para retornar um Objeto por seu id
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	30/09/2010
		-- @param	string pObjectId, id do objeto a ser procurado
		-- @return	{{position,object}} tabela com todos os objetos encontrados, possui sua posicao no layer e o objeto
	-]]
	function self:getObjectById(pObjectId)
		local objects = {}
		for key, obj in pairs(self.mObjects) do 
			if obj:getId() == pObjectId then
				objects[#objects + 1] = { position = key, object = obj }
			end
		end
		return objects
	end
	--[[
		-- Método para retornar 
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	30/09/2010
		-- @param	int pObjectPos, posicao do objeto
		-- @return	Object or nil
	-]]
	function self:getObject(pObjectPos)
		return self.mObjects[pObjectPos]
	end
	--[[
		-- Método para remover um objeto do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
		-- @param	int pObjectPosition, posićao do objeto
	-]]
	function self:removeObject(pObjectPosition)
		if not self.mObjects[pObjectPosition] == nil then
			self.mObjects[pObjectPosition] = nil
		end
	end
	--[[
		-- Método para remover todos objetos com o id fornecido
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	29/09/2010
		-- @version	30/09/2010
		-- @param	string pObjectId, id do objeto
		-- @return	int número de objetos encontrados e removidos
	-]]
	function self:removeObjectById(pObjectId)
		local objects = self:getObjectById(pObjectId)
		for iterator = 1, #objects, 1 do
			self.mObjects[objects[iterator].position] = nil
		end
		return #objects
	end
	--[[
		-- Método para retornar a posićão real do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
		-- @return	{x,y} posicao real
	-]]
	function self:getRealPosition(pPosition)
		local position = {}
		position.x = pPosition.x * self.mScrollSpeed.x
		position.y = pPosition.y * self.mScrollSpeed.y
		return position
	end
	--[[
		-- Método para carregar os tiles no layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
		-- @param	string pSpritePack			, nome do pacote de sprites
		-- @param	string pAnimationPack		, nome do pacote de animaćões
		-- @param	{animation,position} Ptiles	, vetor com os tiles
	-]]
	function self:loadTiles(pTiles, pSpritePack, pAnimationPack)
		GGE_game_log("self:loadTiles()")

		if not pSpritePack		== nil	then self.mSpritePack		= pSpritePack		end
		if not pAnimationPack	== nil	then self.mAnimationPack	= pAnimationPack	end

		for key, tile in pairs (pTiles) do 
	--		GGE_game_log("GGE_Layer().loadTiles() Key: " .. key .. " Animation: " .. tile.animation .. " Posx: " .. tile.position.x .. " posy: " .. tile.position.y)
			self:addTile(
				GGE_Tile:new(
					self.mSpritePack,
					self.mAnimationPack,
					tile.animation,
					tile.position,
					self
				)
			)
		end
		GGE_game_log("self:~loadTiles()")
	end
	--[[
		-- Método para desenhar o layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	20/10/2010
		-- @param	{x,y} pPosition, posićão a desenhar o layer
		-- @details
		--	Esse método desenha todos os tiles e todos os objetos contidos no layer as well
	-]]
	function self:draw(pPosition)
		local position = self:getRealPosition(pPosition)
		for key, tile in pairs( self.mTiles ) do 
			tile:draw(position)
		end
		for key, object in pairs( self.mObjects ) do 
			if object:isActive() then object:draw(position) end
		end
	end
	--[[
		--Função que executa a lógica básica do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	20/10/2010
	-]]
	function self:basicLogic()
		for key, tile in pairs (self.mTiles) do 
			tile:logic()
		end
		for key, object in pairs (self.mObjects) do 
			if object:isActive() then object:logic() end
		end
	end
	--[[
		--Função que executa a lógica do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
	-]]
	function self:logic() self:basicLogic() end
	
	return self
end


