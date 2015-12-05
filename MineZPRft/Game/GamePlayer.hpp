/**
 * @file
 * @author LKostyra (costyrra.xl@gmail.com)
 * @brief  Definition of GamePlayer class
 */

#ifndef __GAME_GAMEPLAYER_H__
#define __GAME_GAMEPLAYER_H__

#include "Renderer/Camera.hpp"
#include "Math/Vector.hpp"

class GamePlayer
{
public:
    GamePlayer();
    ~GamePlayer();

    /**
     * Initialize Game Player.
     *
     * @param camera Camera object, which will be updated by GamePlayer
     */
    void Init(Camera* camera);

    /**
     * Update Camera with current state of Player (position, direction, etc).
     *
     * @remarks The function will be used inside a main loop and will not throw for performance.
     */
    void Update() noexcept;

    /**
     * Set new Position vector
     */
    void SetPosition(const Vector& pos) noexcept;

    /**
     * Rotate Player's camera by @p deltaX radians (yaw rotation).
     *
     * @param deltaX Angle in radians to rotate the camera.
     */
    void ShiftRotationX(const float deltaX) noexcept;

    /**
     * Rotate Player's camera by @p deltaY radians (pitch rotation).
     *
     * @param deltaY Angle in radians to rotate the camera.
     */
    void ShiftRotationY(const float deltaY) noexcept;

    /**
     * Acquire Player position vector.
     */
    const Vector& GetPosition() const noexcept;

    /**
     * Acquire Player direction vector.
     */
    const Vector& GetDirection() const noexcept;

    /**
     * Acquire Player up vector.
     */
    const Vector& GetUp() const noexcept;


private:
    Camera* mCameraPtr;
    Vector mPos;
    Vector mDir;
    Vector mUp;
    float mAngleX;
    float mAngleY;
};

#endif // __GAME_GAMEPLAYER_H__
