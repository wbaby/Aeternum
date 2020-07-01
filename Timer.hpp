#pragma once

//# DO NOT C&P IF U DUNNO HOW TO USE IT
//> he4rtbleed - https://github.com/he4rtbleed/Aeternum

namespace Aeternum
{
	class Timer
	{
	public:
		explicit Timer() :
			m_Timer(std::chrono::high_resolution_clock::now())
		{
		}

		explicit Timer(std::chrono::milliseconds delay) :
			m_Timer(std::chrono::high_resolution_clock::now()),
			m_Delay(std::chrono::duration_cast<std::chrono::high_resolution_clock::duration>(delay))
		{
		}

		bool Update()
		{
			auto now = std::chrono::high_resolution_clock::now();
			if ((now.time_since_epoch() - m_Timer.time_since_epoch()).count() >= m_Delay.count())
			{
				m_Timer = now;
				return true;
			}

			return false;
		}

		void SetDelay(std::chrono::milliseconds delay)
		{
			m_Delay = delay;
		}
	private:
		std::chrono::high_resolution_clock::time_point m_Timer;
		std::chrono::high_resolution_clock::duration m_Delay;
	};
}
