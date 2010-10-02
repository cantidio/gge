print("include: GGE_Layer")
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
function GGE_Layer(pSpritePack,pAnimationPack,pBackground)
	local this			= {}
	this.mBackground	= pBackground		--Referencia ao cenário do layer
	this.mTiles			= {}				--Vetor com os tiles do layer
	this.mObjects		= {}				--Vetor com os objetos do layer
	this.mSpritePack	= pSpritePack		--Localização do arquivo de sprites do layer
	this.mAnimationPack	= pAnimationPack	--Localização do arquivo de animações do layer
	this.mScrollSpeed	= {x = 1, y = 1}	--Velocidade de deslocamento do layer
	this.mId			= ""

	--[[
		-- Método destrutor
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
	-]]
	this.delete = function()
		print("layer delete tiles:")
		for key, tile in pairs (this.mTiles) do 
			io.write(key .. ",")
			tile.delete()
		end
		io.write("\n")

		print ("layer delete objects:")
		for key, object in pairs (this.mObjects) do 
			io.write(key .. ",")
			object.delete()
		end
		io.write("\n")
		this = {}
	end
	--[[
		-- Método para setar o id do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
		-- @param	string pId, id do layer
	-]]
	this.setId = function(pId)
		this.mId = pId
	end
	--[[
		-- Método para pegar o id do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
		-- @return	string, id do layer
	-]]
	this.getId = function()
		return this.mId
	end
	--[[
		-- Método para adicionar um tile ao layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
		-- @param	Tile pTile, tile a ser adicionado
	-]]
	this.addTile = function(pTile)
		this.mTiles[#this.mTiles + 1] = pTile
	end
	--[[
		-- Método que retorna o número de tiles do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	29/09/2010
		-- @return	int
	-]]
	this.getTileNumber = function()
		return #this.mTiles;
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
	this.getTile = function(pTile)
		return this.mTiles[pTile]
	end
	--[[
		-- Funcao que remove um tile
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	13/12/2009
		-- @version	29/09/2010
		-- @param	int pTile, indice do tile
	-]]
	this.removeTile = function (pTile)
		if not this.mTiles[pTile] == nil then
			this.mTiles[pTile].delete()
			this.mTiles[pTile] = nil
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
	this.getBackground = function()
		return this.mBackground
	end
	--[[
		--Função que seta o background do Layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	15/12/2009
		-- @version	29/09/2010
		-- @param	Background pBackground, o nome cenário
	-]]
	this.setBackground = function(pBackground)
		this.mBackground = pBackground
	end
	--[[
		-- Método para adicionar um objeto ao layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	01/10/2010
		-- @version	01/10/2010
		-- @param	GGE_Object pObject, objeto a ser adicionado ao layer
	-]]
	this.addObject = function(pObject)
		pObject.setLayer(this)
		this.mObjects[#this.mObjects + 1] = pObject
	end
	--[[
		--Função que retorna o número de objects do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	29/09/2010
		-- @return	int
	-]]
	this.getObjectNumber = function()
		return #this.mObjects
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
	this.getObjectById = function(pObjectId)
		local objects = {}
		for key, tile in pairs(this.mTiles) do 
			if tile.getId() == pObjectId then
				objects[#objects + 1] = { position = key, object = tile }
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
	this.getObject = function(pObjectPos)
		return this.mObjects[pObjectPos]
	end
	--[[
		-- Método para remover um objeto do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
		-- @param	int pObjectPosition, posićao do objeto
	-]]
	this.removeObject = function(pObjectPosition)
		if not this.mObjects[pObjectPosition] == nil then
			this.mObjects[pObjectPosition].delete()
			this.mObjects[pObjectPosition] = nil
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
	this.removeObjectById = function(pObjectId)
		local objects = this.getObjectById(pObjectId)
		for iterator = 1, #objects, 1 do
			objects[iterator].object.delete()
			this.mObjects[objects[iterator].position] = nil
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
	this.getRealPosition = function(pPosition)
		local position = {}
		position.x = pPosition.x * this.mScrollSpeed.x
		position.y = pPosition.y * this.mScrollSpeed.y
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
	this.loadTiles = function(pTiles,pSpritePack,pAnimationPack)
		GGE_game_log("GGE_Layer().loadTiles()")

		if not pSpritePack == nil then this.mSpritePack = pSpritePack end
		if not pAnimationPack == nil then this.mAnimationPack = pAnimationPack end

		for key, tile in pairs (pTiles) do 
			GGE_game_log("GGE_Layer().loadTiles() Key: " .. key .. " Animation: " .. tile.animation .. " Posx: " .. tile.position.x .. " posy: " .. tile.position.y)
			this.addTile(
				GGE_Tile(
					this.mSpritePack,
					this.mAnimationPack,
					tile.animation,
					tile.position,
					this
				)
			)
		end
	end
	--[[
		-- Método para desenhar o layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	01/10/2010
		-- @param	{x,y} pPosition, posićão a desenhar o layer
		-- @details
		--	Esse método desenha todos os tiles e todos os objetos contidos no layer as well
	-]]
	this.draw = function(pPosition)
		local position = this.getRealPosition(pPosition)
		for key, tile in pairs (this.mTiles) do 
			tile.draw(position)
		end
		for key, object in pairs (this.mObjects) do 
			object.draw(position)
		end
	end
	--[[
		--Função que executa a lógica básica do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	18/03/2009
		-- @version	30/09/2010
	-]]
	this.basicLogic = function()
		for key, tile in pairs (this.mTiles) do 
			tile.logic()
		end
		for key, object in pairs (this.mObjects) do 
			object.logic()
		end
	end
	--[[
		--Função que executa a lógica do layer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	30/09/2010
		-- @version	30/09/2010
	-]]
	this.logic = this.basicLogic
	
	return this
end

