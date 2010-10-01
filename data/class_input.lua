--[[
	-- Classe para representar os inputs
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	26/01/2010
-]]
function GGE_Input()
	local this = {}
	--[[
		-- Método para verificar se o botão start está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	this.buttonStart = function()
		return GGE_input_buttonStart()
	end
	--[[
		-- Método para verificar se o botão cima está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	this. buttonUp = function()
		return GGE_input_buttonUp()
	end
	--[[
		-- Método para verificar se o botão baixo está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	this.buttonDown = function()
		return GGE_input_buttonDown()
	end
	--[[
		-- Método para verificar se o botão esquerda está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	this.buttonLeft = function()
		return GGE_input_buttonLeft()
	end
	--[[
		-- Método para verificar se o botão direita está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	this.buttonRight = function()
		return GGE_input_buttonRight()
	end
	--[[
		-- Método para verificar se o botão1 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	this.button1 = function()
		return GGE_input_button1()
	end
	--[[
		-- Método para verificar se o botão2 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	this.button2 = function()
		return GGE_input_button2()
	end
	--[[
		-- Método para verificar se o botão3 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	this.button3 = function()
		return GGE_input_button3()
	end
	--[[
		-- Método para verificar se o botão4 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	this.button4 = function()
		return GGE_input_button4()
	end
	--[[
		-- Método para verificar se o botão5 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	this.button5 = function()
		return GGE_input_button5()
	end
	--[[
		-- Método para verificar se o botão6 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	this.button6 = function()
		return GGE_input_button6()
	end
	--[[
		-- Método para verificar se o botão7 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	this.button7 = function()
		return GGE_input_button7()
	end
	--[[
		-- Método para verificar se o botão8 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	26/01/2010
		-- @return	bool
	-]]
	this.button8 = function()
		return GGE_input_button8()
	end
	
	return this
end

