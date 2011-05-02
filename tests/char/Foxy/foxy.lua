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
		print("Foxy state: stand")
		self:changeAnimation(0,0)
		self.state = self.stateStanding
	end

	function self:stateStanding()
		if self.mInput:buttonRight() or self.mInput:buttonLeft() then
			self.state = self.stateWalkInit
		elseif self.mInput:button1() then
			self:stateAttackInit(210)
		end
	end

	function self:stateWalkInit()
		print("Foxy state: walk")
		if self.mInput:buttonRight() then
			self:changeAnimation(20,0)
		else
			self:changeAnimation(21,0)
		end
		self.state = self.stateWalking
	end
	
	function self:stateWalking()
		anim = self:getAnimationOn()
		
		if self.mInput:buttonRight() then
			self:addPosition({x=2,y=0})
			if anim.group ~= 20 then
				self:changeAnimation(20,0)
			end
		elseif self.mInput:buttonLeft() then
			self:subPosition({x=2,y=0})
			if anim.group ~= 21 then
				self:changeAnimation(21,0)
			end
		else
			self.state = self.stateStandInit
		end
	end
	
	function self:stateAttackInit(anim)
		self:changeAnimation(anim)
		self.state = self.stateAttack
	end
	
	function self:stateAttack()
		if self:getFrameOn() >= 8 then
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
		
		self:state()
	end
	
	self.state = self.stateBorning

	return self
end

