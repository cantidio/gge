print("include: GGE_Background")
GGE_Background = class()
--[[
	-- Classe que representa um cenário
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	19/03/2009
	-- @version	26/10/1010
	-- @param	int pPointer, endereço do cenário na memória
-]]
function GGE_Background:new()
	local self			= {}
	self.mLayers		= {}		--Vetor com os Layers do cenário
	self.mWidth			= 0			--Largura do cenário
	self.mHeight		= 0			--Altura do cenário
	self.mPosition		= {x=0,y=0}	--Posicão do cenário
	self.mScrollLock	= false		--Se o cenário está podendo dar scrool
	self.mCameraTarget	= nil
	--self.mCameraPosition={x=0,y=0}
	--self.mCameraVelocity={x=1,y=1}
	--[[
		-- Método que retorna o número de layers que o cenário possui
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	17/12/2009
		-- @return	int
	-]]
	function self:getLayerNumber()
		return #self.mLayers
	end
	--[[
		-- Método para retornar o layer indicado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
		-- @param	int pLayerPos, posićão do layer
		-- @return	Layer
	-]]
	function self:getLayer(pLayerPos)
		return self.mLayers[pLayerPos]
	end
	--[[
		-- Método para retornar os layers com o Id indicado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
		-- @param	string playerId, id dos layers que deseja-se recuperar	
		-- @return 	{position,layer}
	-]]
	function self:getLayerById(pLayerId)
		local layers = {}
		for key, lay in pairs(self.mLayers) do
			if lay.getId() == pLayerId then
				layers[#layers + 1] = { position = key, layer = lay }
			end
		end
		return layers
	end
	--[[
		-- Método para adicionar um layer ao cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	01/10/2010
		-- @param	Layer pLayer, layer a ser adicionado
	-]]
	function self:addLayer(pLayer)
		pLayer:setBackground(self)
		self.mLayers[#self.mLayers + 1] = pLayer
	end
	--[[
		-- Método para remover um layer do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	01/10/2010
		-- @param	int pLayerPosition, posićão do layer a ser removido
	-]]
	function self:removeLayer(pLayerPosition)
		if not self.mLayers[pLayerPosition] == nil then
			self.mLayers[pLayerPosition] = nil
		end
	end
	--[[
		-- Método para remover todos os layers com o id desejado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
		-- @param	string pLayerId, id dos layers a serem removidos
		-- @return	int, número de layers removidos
	-]]
	function self:removeLayerById(pLayerId)
		local layers = self:getLayerById(pLayerId)
		for iterator = 1, #layers, 1  do
			self.mLayers[layers[iterator].position] = nil
		end
		return #layers
	end
	--[[
		-- Método que retorna a largura do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	02/01/2010
		-- @version	02/01/2010
		-- @return	int
	-]]
	function self:getWidth()
		return self.mWidth
	end
	--[[
		-- Método que retorna a altura do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	02/01/2010
		-- @version	02/01/2010
		-- @return	int
	-]]
	function self:getHeight()
		return self.mHeight
	end
	--[[
		-- Método que retorna a posição atual do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	26/10/2010
		-- @return	{x,y}
	-]]
	function self:getPosition()
		local aux = {}
		aux.x = self.mPosition.x
		aux.y = self.mPosition.y
		return aux 
	end
	--[[
		-- Método que seta a posição atual do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	02/01/2010
		-- @param	{x,y} pPosition, nova posição do cenário
	-]]
	function self:setPosition(pPosition)
		self.mPosition = pPosition
	end
	--[[
		-- Método que adiciona um valor a posição do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	02/01/2010
		-- @param	int pPosition, valor a ser adicionado a posição do cenário
	-]]
	function self:addPosition(pPosition)
		self.mPosition.x = self.mPosition.x + pPosition.x
		self.mPosition.y = self.mPosition.y + pPosition.y
	end
	--[[
		-- Método que subtrai um valor a posição x do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	02/01/2010
		-- @param	{x,y} pPosition, valor a ser subtraído da posição do cenário
	-]]
	function self:subPosition(pPosition)
		self.mPosition.x = self.mPosition.x - pPosition.x
		self.mPosition.y = self.mPosition.y - pPosition.y
	end
	--[[
		-- Método que trava o scrolling do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
	-]]
	function self:scrollLock()
		self.mScroolLock = true
	end
	--[[
		-- Método que destrava o scrolling do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
	-]]
	function self:scrollUnlock()
		self.mScroolLock = false
	end
	--[[
		-- Método para desenhar o cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	27/10/2010
	-]]
	function self:draw()
		for key, layer in pairs (self.mLayers) do 
			if layer:isActive() then
				layer:draw(self.mPosition)
			end
		end
	end
	--[[
		-- Método que executa a lógica do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	27/10/2010
	-]]
	function self:basicLogic()
		self:cameraLogic()
		for key, layer in pairs (self.mLayers) do 
			if layer:isActive() then
				layer:logic()
			end
		end
	end

	--[[
		-- Method that executes the logic behind the camera
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	25/10/2010
		-- @version	19/05/2011
		-- @todo	quando a largura da tela é maior que a largura do cenário da pau
	-]]
	function self:cameraLogic()
		if self.mCameraTarget then
			local cameraPos	 	= self:getPosition()
			local targetPos  	= self.mCameraTarget:getPosition()
			local window_width	= GGE_game_getWidth()
			local window_height	= GGE_game_getHeight()
			
			
			if	targetPos.x >= (window_width/2) then
				if targetPos.x <= (self.mWidth - window_width/2)		then
					cameraPos.x = -1 * (targetPos.x - window_width/2 )
				elseif targetPos.x >= (self.mWidth - window_width/2)	then
					cameraPos.x = -1 * (self.mWidth - window_width)
				end
			elseif targetPos.x <= (window_width/2) then
				cameraPos.x = 0
			end
			
			if	targetPos.y >= (window_height/2) then
				if targetPos.y <= (self.mHeight - window_height/2) then
					cameraPos.y = -1 * (targetPos.y - window_height/2 )
				elseif targetPos.y >= (self.mHeight - window_height/2) then
					cameraPos.y = -1 * (self.mHeight - window_height)
				end
			elseif targetPos.y <= (window_height/2) then
				cameraPos.y = 0
			end
			
			self:setPosition(cameraPos)
		end
	end
	--[[
		-- Method that sets the target object of the camera
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	25/10/2010
		-- @version	25/10/2010
		-- @param	GGE_Object pObject, the object that will be followed
	-]]
	function self:setCameraTarget(pObject)
		self.mCameraTarget = pObject
	end
	
	self.logic = self.basicLogic

	return self
end

