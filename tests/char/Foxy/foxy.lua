Foxy = class()
function Foxy:new(pPosition, pLayer)
	local self = GGE_Player:new(
		Foxy.__dir .. "foxy.gsp",
		Foxy.__dir .. "foxy.gap",
		pLayer,
		pPosition 
	)
			
	function self:stateBorning()
		print("mature state: borning")
		--this.setAfterImageMethodTrans(0.5)
		--this.setAfterImageMethodAdd({r=200,g=0,b=0},{r=0,g=0,b=0},0.5)
		self.state = self.stateStandInit
	end

	function self:stateStandInit()
		print("mature state: stand")
		self:changeAnimation(0,0)
		self.state = self.stateStanding
	end

	function self:stateStanding()
		
	end

	function self:logic()
		self:basicLogic()
		if self.mInput:buttonDown()  then
			self:addPosition({x=0,y=3})
		elseif self.mInput:buttonUp() then
			self:subPosition({x=0,y=3})
		end
		
		if self.mInput:buttonRight() then
			self:addPosition({x=3,y=0})
		elseif self.mInput:buttonLeft() then
			self:subPosition({x=3,y=0})
		end

		self:state()
	end
	
	self.state = self.stateBorning

	return self
end

