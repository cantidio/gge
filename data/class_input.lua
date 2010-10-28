print("include: GGE_Input")
GGE_Input = class()
--[[
	-- Classe para representar os inputs
	--
	-- @author	Cantidio Oliveira Fontes
	-- @since	26/01/2010
	-- @version	22/10/2010
-]]
function GGE_Input:new()
	local self = {}
	--[[
		-- Método para verificar se o botão start está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version\t22/10/2010
		-- @return	bool
	-]]
	function self:buttonStart()
		return GGE_input_buttonStart()
	end
	--[[
		-- Método para verificar se o botão cima está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version\t22/10/2010
		-- @return	bool
	-]]
	function self:buttonUp()
		return GGE_input_buttonUp()
	end
	--[[
		-- Método para verificar se o botão baixo está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version\t22/10/2010
		-- @return	bool
	-]]
	function self:buttonDown()
		return GGE_input_buttonDown()
	end
	--[[
		-- Método para verificar se o botão esquerda está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version\t22/10/2010
		-- @return	bool
	-]]
	function self:buttonLeft()
		return GGE_input_buttonLeft()
	end
	--[[
		-- Método para verificar se o botão direita está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version\t22/10/2010
		-- @return	bool
	-]]
	function self:buttonRight()
		return GGE_input_buttonRight()
	end
	--[[
		-- Método para verificar se o botão1 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version\t22/10/2010
		-- @return	bool
	-]]
	function self:button1()
		return GGE_input_button1()
	end
	--[[
		-- Método para verificar se o botão2 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version\t22/10/2010
		-- @return	bool
	-]]
	function self:button2()
		return GGE_input_button2()
	end
	--[[
		-- Método para verificar se o botão3 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version\t22/10/2010
		-- @return	bool
	-]]
	function self:button3()
		return GGE_input_button3()
	end
	--[[
		-- Método para verificar se o botão4 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version\t22/10/2010
		-- @return	bool
	-]]
	function self:button4()
		return GGE_input_button4()
	end
	--[[
		-- Método para verificar se o botão5 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version\t22/10/2010
		-- @return	bool
	-]]
	function self:button5()
		return GGE_input_button5()
	end
	--[[
		-- Método para verificar se o botão6 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version\t22/10/2010
		-- @return	bool
	-]]
	function self:button6()
		return GGE_input_button6()
	end
	--[[
		-- Método para verificar se o botão7 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version\t22/10/2010
		-- @return	bool
	-]]
	function self:button7()
		return GGE_input_button7()
	end
	--[[
		-- Método para verificar se o botão8 está apertado
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	26/01/2010
		-- @version	22/10/2010
		-- @return	bool
	-]]
	function self:button8()
		return GGE_input_button8()
	end
	--[[
		-- Method that cleans the buffer
		--
		-- @author	Cantidio Oliveira Fontes
		-- @since	27/10/2010
		-- @version	27/10/2010
	-]]
	function self:cleanBuffer()
		return GGE_input_cleanKeyBuffer()
	end
	
	return self
end

