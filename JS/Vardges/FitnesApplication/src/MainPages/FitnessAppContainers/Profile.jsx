import React, { useState } from 'react'
import Food from './FoodPage/General'

import Icon from '@mdi/react'
import {
    mdiHome,
    mdiBell,
    mdiAccount,
    mdiChartLine,
    mdiFood,
} from '@mdi/js'

import {
    H4,
    Card,
    ToggleButton,
} from 'ui-neumorphism'


function Profile({ dark, size }) {
    return (
        <Card flat dark={dark} className='fitness-app-container'>
            <Card flat className='fitness-app-wrapper overflow-hidden'>
                <Card
                    rounded
                    width={300}
                    height={600}
                    className={`fitness-app ${size === 'xs' ? 'fitness-app--small' : ''
                        } overflow-hidden`}
                >
                    <div
                        style={{
                            display: 'flex',
                            marginTop: '8px',
                            // alignItems: 'center',
                            justifyContent: 'space-between'
                        }}
                    >
                        <H4 dark={dark} style={{ fontWeight: '500' }}>
                            Profile
              </H4>
                    </div>

                    <div
                        style={{
                            display: 'flex',
                            width: '252px',
                            // alignItems: 'center',
                            justifyContent: 'center'
                        }}
                    >
                    </div>
                    <Card style={{ marginTop: "25px" }}>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiAccount} width={50} height={50} />
                        </ToggleButton>
                        <h3>Vardges</h3>
                        <h3>Karapetyan</h3>
                        <h5>vardges.karapetyan.20@gmail.com</h5>
                    </Card>

                    <div className='fitness-app-nav-bar'>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiHome} size={0.9} />
                        </ToggleButton>
                        <ToggleButton selected dark={dark} >
                            <Icon path={mdiChartLine} size={0.8} />
                        </ToggleButton>
                        <ToggleButton selected dark={dark} >
                            <Icon path={mdiFood} size={0.8} />
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiBell} size={0.8} />
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiAccount} size={0.9} color='var(--primary)' />
                        </ToggleButton>
                    </div>
                </Card>
            </Card>
        </Card>
    )
}

export default Profile;
