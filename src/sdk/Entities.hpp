#pragma once

#ifdef GetProp
#undef GetProp
#endif
#ifdef SetProp
#undef SetProp
#endif

namespace rage
{
    struct arg_t
    {
    public:
        enum class val_t : uint8_t
        {
            Int,
            Float,
            String,
            Null,

            Player,
            Vehicle,
            Colshape,
            Checkpoint,
            Marker,
            Blip,
            Pickup
        };

        arg_t() : type(val_t::Null) { }
        arg_t(int i) : type(val_t::Int) { v.i = i; }
        arg_t(float f) : type(val_t::Float) { v.f = f; }
        arg_t(const wchar_t *str) : type(val_t::String) { v.str = new wchar_t[wcslen(str)]; wcscpy(v.str, str); }
        // todo

        bool IsNull() const { return type == val_t::Null; }
        bool IsInt() const { return type == val_t::Int; }
        bool IsFloat() const { return type == val_t::Float; }
        bool IsString() const { return type == val_t::String; }

        int Int() const { return (type == val_t::Int) ? v.i : 0; }
        float Float() const { return (type == val_t::Float) ? v.f : 0.0f; }
        const wchar_t *String() const { return (type == val_t::String) ? v.str : L""; }

        ~arg_t() { if (type == val_t::String && v.str) delete[] v.str; }

    private:
        union
        {
            int i;
            float f;
            wchar_t *str;
        } v;

        val_t type;
    };

    struct args_t
    {
    public:
        args_t(arg_t *data, size_t len)
                : m_data(data), m_len(len) { }

        size_t Length() const { return this->m_len; }
        const arg_t& operator[](int id) const { if (id >= this->m_len) return arg_t{}; return this->m_data[id]; }

    private:
        size_t m_len;
        arg_t *m_data;
    };

    using hash_t = uint32_t;

    class IPlayer;
    class IVehicle;
    class IColshape;
    class ICheckpoint;
    class IMarker;
    class IBlip;
    class IPickup;

    using Entity = IEntity;

    class IPlayer
            : public Entity
    {
    public:
        virtual void Kick(const char *reason) = 0;
        virtual void Ban(const char *reason) = 0;
        virtual void OutputChatBox(const std::u16string& text) = 0;
        virtual void Notify(const std::u16string& text) = 0;
    private:
        virtual void _Call(const std::u16string& eventName, const arg_t *arguments = nullptr, size_t count = 0) = 0;
        virtual void _Invoke(uint64_t nativeHash, const arg_t *arguments = nullptr, size_t count = 0) = 0;
    public:
        virtual void Spawn(const vector3& pos, float heading) = 0;
        virtual void GiveWeapon(hash_t hash, uint16_t ammo) = 0;
        virtual void PutIntoVehicle(IVehicle *vehicle, uint8_t seatId) = 0;
        virtual void RemoveFromVehicle() = 0;
        virtual void PlayAnimation(const std::string& dict, const std::string& name, float speed = 8.f, int flags = 0) = 0;
        virtual void PlayScenario(const std::string& scenario) = 0;
        virtual void StopAnimation() = 0;
        virtual const clothData_t& GetClothes(uint8_t id) = 0;
        virtual void SetClothes(uint8_t id, const clothData_t& clothes) = 0;
        virtual const propData_t& GetProp(uint8_t id) = 0;
        virtual void SetProp(uint8_t id, const propData_t& prop) = 0;
        virtual void Eval(const std::string& code) = 0;
        // todo

    public:
        template<typename ...Args>
        void Call(const std::u16string& eventName, Args&&... args)
        {
            const int count = sizeof...(Args);

            if (count == 0)
                this->_Call(eventName);
            else
            {
                arg_t arguments[count] = { arg_t(std::forward<Args>(args))... };
                this->_Call(eventName, arguments, count);
            }
        }

        template<typename ...Args>
        void Invoke(uint64_t hash, Args&&... args)
        {
            const int count = sizeof...(Args);

            if (count == 0)
                this->_Invoke(hash);
            else
            {
                arg_t arguments[count] = { arg_t(std::forward<Args>(args))... };
                this->_Invoke(hash, arguments, count);
            }
        }
    };

    class IVehicle
            : public Entity
    {
    public:
        virtual void Repair() = 0;
        // todo
    };

    class IColshape
            : public Entity
    {
    public:
        // todo
    };

    class ICheckpoint
            : public Entity
    {
    public:
        // todo
    };

    class IMarker
            : public Entity
    {
    public:
        // todo
    };

    class IBlip
            : public Entity
    {
    public:
        // todo
    };

    class IPickup
            : public Entity
    {
    public:
        // to be continued
    };

    class IObject
            : public Entity
    {
    public:
        // to be continued
    };

}