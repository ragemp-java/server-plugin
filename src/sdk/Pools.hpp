#pragma once

#include "Entities.hpp"

namespace rage
{
	template<class T>
	using Pool = IPool<T>;

	class IPlayerPool
			: public Pool<IPlayer>
	{
	public:
		// todo
	};

	class IVehiclePool
			: public Pool<IVehicle>
	{
	public:
		// todo
	};

	class IColshapePool
			: public Pool<IColshape>
	{
	public:
		// todo
	};

	class ICheckpointPool
			: public Pool<ICheckpoint>
	{
	public:
		// todo
	};

	class IMarkerPool
			: public Pool<IMarker>
	{
	public:
		// todo
	};

	class IBlipPool
			: public Pool<IBlip>
	{
	public:
		// todo
	};

	class IPickupPool
			: public Pool<IPickup>
	{
	public:
		// todo
	};

	class IObjectPool
			: public Pool<IObject>
	{
	public:
		// todo
	};
}