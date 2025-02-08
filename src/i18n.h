#ifndef I18N_H_
#define I18N_H_

#include <cstdint>
#include <map>
#include <string>

enum class Language : uint32_t{
    ENGLISH,
    CHINESE,
    MAX
};

// 这个缩写通常用于表示程序或系统设计中，支持多种语言和文化的功能。
// Internationalization
class I18n{
    public:
        enum class Key{
            ASK_KEY_MAP,
            INPUT_ERROR,
            LOAD_PROGRESS_FAIL,
            ASK_QUIT,
            ASK_SAVE,
            ASK_SAVE_PATH,
            FILE_EXIST_ERROR,
            CONTINUE,
            UNDO_ERROR,
            CONGRATULATION,
            NOT_COMPLETED,
            ASK_DIFFICULTY,
        };

        using Dict = std::map<Key, std::string>;

        static I18n& Instance();
        void SetLanguage(Language);
        std::string Get(Key) const;

    private:
        // 将默认构造函数放在私有部分，只允许该类存在一个实例
        I18n();

        Dict * dict_;
};

#endif
