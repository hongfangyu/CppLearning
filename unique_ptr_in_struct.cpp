struct StructUniquePtr {

    std::unique_ptr<char[]> uniquePtrMember;

    StructUniquePtr() = default;

    StructUniquePtr(const StructUniquePtr& rhs) :
    uniquePtrMember(std::move(const_cast<StructUniquePtr &>(rhs).uniquePtrMember))
    {}

    StructUniquePtr& operator=(const StructUniquePtr& rhs) noexcept
    {
        if (&rhs != this) {
            uniquePtrMember = std::move(const_cast<StructUniquePtr &>(rhs).uniquePtrMember);
        }
        return *this;
    }

    StructUniquePtr(StructUniquePtr&& rhs) noexcept : uniquePtrMember(std::move(rhs.uniquePtrMember))
    {}

    StructUniquePtr& operator=(StructUniquePtr&& rhs) noexcept
    {
        uniquePtrMember = std::move(rhs.uniquePtrMember);
        return *this;
    }

    ~StructUniquePtr() = default;

};

struct NormalStruct {
    StructUniquePtr structUniquePtr;
    int size;
};
