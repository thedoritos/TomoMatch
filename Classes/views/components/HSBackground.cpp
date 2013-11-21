//
//  HSBackground.cpp
//  TomoMatch
//
//  Created by thedoritos on 2013/11/14.
//
//

#include "HSBackground.h"

bool HSBackground::init()
{
    ccColor4B color = ccc4(46, 169, 223, 255);  // Tsuyukusa
    
    if (!CCLayerColor::initWithColor(color)) return false;
    
    m_label = CCLabelTTF::create("TomoMatch", "Helvetica", 32.0f);
    m_label->retain();
    m_slideRate = 0.0f;
    
    return true;
}

void HSBackground::update(float dt)
{
    m_slideRate += dt * 0.2f;
    if (m_slideRate > 1.0f) {
        m_slideRate = 0.0f;
    }
}

void HSBackground::draw()
{
    // Draw parent.
    CCLayerColor::draw();
    
    // Draw text lines.
    kmGLPushMatrix();
    {
        kmGLTranslatef(0.0f, -150.0f, 0.0f);
        kmGLRotatef(15.0f, 0.0f, 0.0f, 1.0f);
        
        for (int i = 0; i < 12; i++) {
            kmGLPushMatrix();
            {
                if (i % 2 == 0) {
                    kmGLTranslatef(200 * (m_slideRate - 1.0f) + 20.0f * i, 0.0f, 0.0f);
                } else {
                    kmGLTranslatef(200 * (0.0f - m_slideRate) + 20.0f * i, 0.0f, 0.0f);
                }
                
                for (int j = 0; j < 5; j++) {
                    m_label->draw();
                    kmGLTranslatef(200.0f, 0.0f, 0.0f);
                }
            }
            kmGLPopMatrix();
            kmGLTranslatef(0.0f, 100.0f, 0.0f);
        }
    }
    kmGLPopMatrix();
}

void HSBackground::setLabel(const std::string &label)
{
    // Dispose old.
    m_label->release();
    
    // Create new.
    m_label = CCLabelTTF::create(label.c_str(), "Helvetica", 32.0f);
    m_label->retain();
}
