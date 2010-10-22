Mammon=class()

function Mammon:new(pPosition,pLayer)
	local self = GGE_Player:new(
		Mammon.__dir .. "mammon.gspk",
		Mammon.__dir .. "mammon.gapk",
		pLayer,
		pPosition 
	)
	
	function self:stateBorning()
		print("state: borning")
		--this.setAfterImageMethodTrans(0.5)
		--this.setAfterImageMode(true,5,10)
		--this.setAfterImageMethodAdd({blue=200},{},0.5)
		self.state = self.stateStandInit
		self:setMirroring(Mirroring.HFlip)
	end

	function self:stateStandInit()
		self:changeAnimationByIndex(1)
		self.state = self.stateStanding
	end

	function self:stateStanding()
		if self.mInput:button1() then
			print("state: stand")
			self.state = self.stateAttackInit
		elseif self.mInput:buttonDown() then
			self.state= self.stateAInit
		elseif self.mInput:buttonRight() or self.mInput:buttonLeft() then
			self.state = self.stateWalkInit
		end
	end

	function self:stateAInit()
		self:changeAnimationByIndex(2)
		self.state = self.stateAing
	end
	
	function self:stateAing()
		if not self.mInput:buttonDown() then
			self.state = self.stateStandInit
		end
	end
	
	function self:stateWalkInit()
		print("state: walk")
		self:changeAnimationByIndex(8);
		self.state = self.stateWalking
	end
	
	function self:stateWalking()
		print("state: walking")
		if self.mInput:button1()			then
			self.state = self.stateAttackInit
		elseif self.mInput:buttonDown()		then
			self.state = self.stateAInit
		elseif self.mInput:buttonRight()	then 
			self:addPosition({x=5,y=0})
		elseif self.mInput:buttonLeft() 	then
			self:subPosition({x=5,y=0})
		else
			self.state = self.stateStandInit
		end
	end
	
	function self:stateAttackInit()
		print("state attack")
		--this.setAfterImageMode(true,30,5)
		self:changeAnimation(100,0)
		self.state = self.stateAttacking
	end

	function self:stateAttacking()
		if not self:animationIsPlaying() then
			--this.setAfterImageMode(false,1,1)
			self.state = self.stateStandInit
		end
	end

	function self:logic()
		if self.mInput:buttonUp()		then 
			self:subPosition({x=0,y=1})
		elseif self.mInput:buttonDown() then
			self:addPosition({x=0,y=1})
		end
		self:basicLogic()
		self:state()
	end

	self.state = self.stateBorning	
	return self
end

