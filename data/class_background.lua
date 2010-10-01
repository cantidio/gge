print("include: GGE_Background")
--[[
	-- Classe que representa um cenário
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	19/03/2009
	-- @version	01/10/1010
	-- @param	int pPointer, endereço do cenário na memória
-]]
function GGE_Background()
	local this			= {}
	this.mLayers		= {}		--Vetor com os Layers do cenário
	this.mWidth			= 0			--Largura do cenário
	this.mHeight		= 0			--Altura do cenário
	this.mPosition		= {x=0,y=0}	--Posicão do cenário
	this.mScrollLock	= false		--Se o cenário está podendo dar scrool
	
	--[[
		-- Método que retorna o número de layers que o cenário possui
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	17/12/2009
		-- @return	int
	-]]
	this.getLayerNumber = function()
		return #this.mLayers
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
	this.getLayer = function(pLayerPos)
		return this.mLayers[pLayerPos]
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
	this.getLayerById = function(pLayerId)
		local layers = {}
		for key, lay in pairs(this.mLayers) do
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
	this.addLayer = function(pLayer)
		pLayer.setBackground(this)
		this.mLayers[#this.mLayers+1] = pLayer
	end
	--[[
		-- Método para remover um layer do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	01/10/2010
		-- @param	int pLayerPosition, posićão do layer a ser removido
	-]]
	this.removeLayer = function(pLayerPosition)
		if not this.mLayers[pLayerPosition] == nil then
			this.mLayers[pLayerPosition].delete()
			this.mLayers[pLayerPosition] = nil
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
	this.removeLayerById = function(pLayerId)
		local layers = this.getLayerById(pLayerId)
		for iterator = 1, #layers, 1  do
			layers[iterator].layer.delete()
			this.mLayers[layers[iterator].position] = nil
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
	this.getWidth = function()
		return this.mWidth
	end
	--[[
		-- Método que retorna a altura do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	02/01/2010
		-- @version	02/01/2010
		-- @return	int
	-]]
	this.getHeight = function()
		return this.mHeight
	end
	--[[
		-- Método que retorna a posição atual do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	02/01/2010
		-- @return	{x,y}
	-]]
	this.getPosition = function()
		return this.mPosition
	end
	--[[
		-- Método que seta a posição atual do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	02/01/2010
		-- @param	{x,y} pPosition, nova posição do cenário
	-]]
	this.setPosition = function(pPosition)
		this.mPosition = pPosition
	end
	--[[
		-- Método que adiciona um valor a posição do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	02/01/2010
		-- @param	int pPosition, valor a ser adicionado a posição do cenário
	-]]
	this.addPosition = function(pPosition)
		this.mPosition.x = this.mPosition.x + pPosition.x
		this.mPosition.y = this.mPosition.y + pPosition.y
	end
	--[[
		-- Método que subtrai um valor a posição x do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	02/01/2010
		-- @param	{x,y} pPosition, valor a ser subtraído da posição do cenário
	-]]
	this.subPosition = function(pPosition)
		this.mPosition.x = this.mPosition.x - pPosition.x
		this.mPosition.y = this.mPosition.y - pPosition.y
	end
	--[[
		-- Método que trava o scrolling do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
	-]]
	this.scrollLock = function()
		this.mScroolLock = true
	end
	--[[
		-- Método que destrava o scrolling do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	19/03/2009
		-- @version	19/03/2009
	-]]
	this.scrollUnlock = function()
		this.mScroolLock = false
	end
	--[[
		-- Método para desenhar o cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
	-]]
	this.draw = function()
		for key, layer in pairs (this.mLayers) do 
			layer.draw(this.mPosition)
		end
	end
	--[[
		-- Método que executa a lógica do cenário
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
	-]]
	this.basicLogic = function()
		for key, layer in pairs (this.mLayers) do 
			layer.logic()
		end
	end

	this.logic = this.basicLogic
	return this
end

