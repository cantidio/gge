Mature = class()
function Mature:new(pPosition, pLayer)
	local self = GGE_Player:new(
		Mature.__dir .. "mature.gspk",
		Mature.__dir .. "mature.gapk",
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
		if self.mInput:button1() then
			self.state = self.stateKick1Init
		elseif self.mInput:button2() then
			self.state = self.stateKick2Init
		end
	end

	function self:stateKick1Init()
		print("mature state: kick1")
		--this.setAfterImageMode(true,2,10)
		self:changeAnimation(10,0)
		self.state = self.stateKicking1
	end

	function self:stateKicking1()
		if not self:animationIsPlaying() then
			--this.setAfterImageMode(false,1,1)
			self.state = self.stateStandInit
		end
	end

	function self:stateKick2Init()
		print("mature state: kick2")
		--this.getBackground().getlayer)(.getBac
		--this.setAfterImageMode(true,2,10)
		self:changeAnimation(10,1)
		self.state = self.stateKicking2
	end

	function self:stateKicking2()
		if not self:animationIsPlaying() then
			--this.setAfterImageMode(false,1,1)
			self.state = self.stateStandInit
		end
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

